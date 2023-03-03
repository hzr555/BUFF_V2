#include "buff.h"
#include "EulerAngle.h"
using namespace std;
using namespace cv;
extern image_transport::Publisher publisher;

/*extern template< typename T1,typename T2 >
void log(T1 name,T2 text);*/

template< typename T1,typename T2 >
void log(T1 name,T2 text){
    cout << name << ":" << text << endl;
}

Buff &Buff::operator<<(cv::Mat &input){
    Mat video2 = input.clone();
    circle(video2, Point(video2.cols, video2.rows) / 2, 10, Scalar(255, 255, 255), 1);
        vector<Mat> channels;
        split(input, channels);//分离通道
        //threshold(channels.at(2) - channels.at(0), input, 110, 255, THRESH_BINARY_INV);//二值化 红色
        threshold(channels.at(0) - channels.at(2), input, 115, 255, THRESH_BINARY_INV);//二值化 蓝色
        imshow("threshold",input);
        //blur(input,input,Point(3, 3));
        Mat threshold = input.clone();

        Mat video3;
        morphologyEx(input, video3, MORPH_OPEN, element1);//z
        imshow("video3",video3);

        input = video3.clone();
        floodFill(input, Point(0, 0), Scalar(0));//漫水
        morphologyEx(input, input, MORPH_CLOSE, element2);//闭运算
        imshow("floodFill",input);

        Point2d c;//圆心
        double r = 0;//半径
       
        vector<vector<Point>> contours2;
        findContours(video3, contours2, RETR_TREE, CHAIN_APPROX_SIMPLE);
        for (int i = 0; i < contours2.size(); i++){
            Rect boundRect = boundingRect(contours2[i]);
            double angle_divided = (double)boundRect.width / (double)boundRect.height;
            Point2d rect_center = (boundRect.br() + boundRect.tl())/2;
            int rect_area = boundRect.width * boundRect.height;
            //通过长宽比，面积大小以及和装甲板的距离筛选圆心
            if(angle_divided >= 0.8 && angle_divided <= 1.2 && get_distance(box_center,rect_center) > 70 && get_distance(box_center,rect_center) < 150 && rect_area < box_area/1.5 && rect_area > box_area/5){
                rectangle(video2, boundRect.tl(), boundRect.br(), Scalar(255, 102, 204), 2);
                c = rect_center;
                break;
            }
        }

        vector<vector<Point>> contours;
        findContours(input, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);//找轮廓

        bool hasTarget = 0;
        for (int i = 0; i < contours.size(); i++){
            int area = contourArea(contours[i]);//计算轮廓面积
            if (area < 2000){
                
                Point2f rect[4];
                RotatedRect box1 = minAreaRect(Mat(contours[i]));//获取最小外接矩阵
                circle(video2, Point(box1.center.x, box1.center.y), 5, Scalar(255, 0, 0), -1, 8);//绘制最小外接矩形的中心点
                box1.points(rect);  //把最小外接矩形四个端点复制给rect数组
                for (int j = 0; j < 4; j++){
                    line(video2, rect[j], rect[(j + 1) % 4], Scalar(0, 255, 0), 2, 8);//绘制最小外接矩形每条边
                }

                //points.push_back(box1.center);//储存最小外接矩形中心点
                box_center = box1.center;
                box_area = area;
                r = get_distance(c,box1.center);

                //LeastSquaresCircleFitting(points, c, r);//拟合圆
                circle(video2, c, r, Scalar(0, 0, 255), 2, 8);//绘制圆
                circle(video2, c, 4, Scalar(255, 0, 0), -1, 8);//绘制圆

                if (this->last_angle != 0xFFFF){
                    double angle = (this->get_cicrle_angle(c,r,box1.center))-(last_angle);
                    log("angle",(this->get_cicrle_angle(c,r,box1.center)*180.0)/CV_PI);
                    if(fabs(angle) > CV_PI/3 || frame > 100) goto skip_direction_calc;
                    /*if(angle < 0){
                        this->direction = true;
                    }else if(angle > 0){
                        this->direction = false;
                    }*/
                    
                }
                skip_direction_calc:
                
                log("direction",direction);
                double time_now = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() * 0.001;
                if((time_now - this->timestamp) > 5.0) frame = 0;
                this->timestamp = time_now;

                double perdict_target_angle = this->perdict_angle(this->get_cicrle_angle(c,r,box1.center),direction,this->windmill_spd_mode);
                Point dest_point;
                dest_point.x = (c.x + (0.99 * r * cos(perdict_target_angle)));
                dest_point.y = (c.y - (0.99 * r * sin(perdict_target_angle)));
                circle(video2, dest_point, 8, Scalar(255, 0, 0), 3, 8);

                log("perdict_target_angle",fmod(perdict_target_angle,2*CV_PI)*180.0/CV_PI);
                
                //cout << perdict_target_angle;
                /*double focus = 60.0;
                double yaw = (atan(((dest_point.x) - (input.cols / 2.0)) * im_real_weights / 100 / focus) * 180 / CV_PI);
                double pitch = (atan(((dest_point.y) - (input.rows / 2.0)) * im_real_weights / 100 / focus) * 180 / CV_PI);
                cout << yaw << "," << pitch;*/
                EulerAngle targe_armor_angle = this->getAngle(cv::Point(input.cols / 2, input.rows / 2),dest_point);
                
                log("yaw",targe_armor_angle.yaw);
                log("pitch",targe_armor_angle.pitch);
                log("frame",frame);

                log("windmill_spd_mode",this->windmill_spd_mode);
                log("targetColor",(this->targetColor == IdentityColor::IDENTITY_RED));
                if(r < 200 && c.x > 0 && c.y > 0 && c.x < input.cols && c.y < input.rows && dest_point.x > 0 && dest_point.y > 0 && dest_point.x < input.cols && dest_point.y < input.rows){
                    hasTarget = 1;
                    targetTo(targe_armor_angle, distance_, 1,1);
                }else{
                    cout << "r too large" << endl;
                    targetTo({0,0}, distance_, 0,0);
                }
                

                if((frame%5) == 0){
                    this->last_angle = this->get_cicrle_angle(c,r,box1.center);
                }
                cout << endl;
                break;
            }
        }
        if(!hasTarget) targetTo({0,0}, distance_, 0,0);

        frame++;
        imshow("result", video2);
        std_msgs::Header header;
	    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(header, "bgr8", video2).toImageMsg();
        publisher.publish(msg);
        waitKey(1);
        return *this;
}

void Buff::update(const uart_process_2::uart_receive &receive){
    //printf("%d\n",receive.mod);
	if(receive.mod >= 10 && receive.mod <=13) {
		if(this->disabled) { // 从非打符状态切换到打符状态 
			this->disabled = false;
		}
        switch (receive.mod){
        case 10:
            this->windmill_spd_mode = false;
            //this->direction = CLOCKWISE;
            break;
        case 11:
            this->windmill_spd_mode = false;
            //this->direction = COUNTERCLOCKWISE;
            break;
        case 12:
            this->windmill_spd_mode = true;
            //this->direction = CLOCKWISE;
            break;
        case 13:
            this->windmill_spd_mode = true;
            //this->direction = COUNTERCLOCKWISE;
            break;
        default:
            break;
        }
	} else {
		this->disabled = true; // This stops feeding new images.
	}
    //和自瞄相反
	if (receive.red_blue == 1){
		//std::cout << "寻找目标颜色：红色" << std::endl;
		this->targetColor = IdentityColor::IDENTITY_RED;
	}else{
		//std::cout << "寻找目标颜色：蓝色" << std::endl;
		this->targetColor = IdentityColor::IDENTITY_BLUE;
	}
}

Buff::Buff(IdentityColor targetColor) : targetColor(targetColor){

}
double Buff::get_cicrle_angle(Point c,double r,Point p){
    double angle = asin((c.y - p.y)/r);
    if(p.x - c.x < 0) angle = CV_PI - angle;
    if(angle < 0) angle = 2 * CV_PI + angle;
    return angle;
}

double Buff::get_distance(Point p1,Point p2){
    return sqrtf(powf((p1.x - p2.x),2) + powf((p1.y - p2.y),2));
}

double Buff::perdict_angle(double angle,bool direction,bool windmill_spd_mode){
    double res;
    double angle_addon;
    if(windmill_spd_mode){
        double timestamp = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() * 0.001;
        angle_addon = -((angle) + (0.416667 * cos(1.884 * (timestamp))) - (1.305 * timestamp));
        res = (((-0.416667) * cos(1.884 * (timestamp + this->time_delay))) + (1.305 * (timestamp + this->time_delay))+ (direction ? angle_addon*-1 : angle_addon));
        res = 2*angle - res;
    }
    else{
        angle_addon = 0.01 * CV_PI;
        res = angle + (direction ? (this->angle_offset+angle_addon)*-1 : (this->angle_offset+angle_addon));
    }
    //if(windmill_spd_mode) res *= -1;
    return res;
    ///return angle;
}


//最小二乘法拟合圆，弃用
int LeastSquaresCircleFitting(vector<cv::Point2d> &m_Points, cv::Point2d &Centroid, double &dRadius)//拟合圆函数
{
    if (!m_Points.empty())
    {
        int iNum = (int)m_Points.size();
        if (iNum < 3)   return 1;
        double X1 = 0.0;
        double Y1 = 0.0;
        double X2 = 0.0;
        double Y2 = 0.0;
        double X3 = 0.0;
        double Y3 = 0.0;
        double X1Y1 = 0.0;
        double X1Y2 = 0.0;
        double X2Y1 = 0.0;
        vector<cv::Point2d>::iterator iter;
        vector<cv::Point2d>::iterator end = m_Points.end();
        for (iter = m_Points.begin(); iter != end; ++iter)
        {
            X1 = X1 + (*iter).x;
            Y1 = Y1 + (*iter).y;
            X2 = X2 + (*iter).x * (*iter).x;
            Y2 = Y2 + (*iter).y * (*iter).y;
            X3 = X3 + (*iter).x * (*iter).x * (*iter).x;
            Y3 = Y3 + (*iter).y * (*iter).y * (*iter).y;
            X1Y1 = X1Y1 + (*iter).x * (*iter).y;
            X1Y2 = X1Y2 + (*iter).x * (*iter).y * (*iter).y;
            X2Y1 = X2Y1 + (*iter).x * (*iter).x * (*iter).y;
        }
        double C = 0.0;
        double D = 0.0;
        double E = 0.0;
        double G = 0.0;
        double H = 0.0;
        double a = 0.0;
        double b = 0.0;
        double c = 0.0;
        C = iNum * X2 - X1 * X1;
        D = iNum * X1Y1 - X1 * Y1;
        E = iNum * X3 + iNum * X1Y2 - (X2 + Y2) * X1;
        G = iNum * Y2 - Y1 * Y1;
        H = iNum * X2Y1 + iNum * Y3 - (X2 + Y2) * Y1;
        a = (H * D - E * G) / (C * G - D * D);
        b = (H * C - E * D) / (D * D - G * C);
        c = -(a * X1 + b * Y1 + X2 + Y2) / iNum;
        double A = 0.0;
        double B = 0.0;
        double R = 0.0;
        A = a / (-2);
        B = b / (-2);
        R = double(sqrt(a * a + b * b - 4 * c) / 2);
        Centroid.x = A;
        Centroid.y = B;
        dRadius = R;
        return 0;
    }
    else
        return 1;
    return 0;
}
