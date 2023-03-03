#include <bits/stdc++.h>
#include <opencv4/opencv2/opencv.hpp>
#include <ros/ros.h>
#include <sagitari_debug/sagitari_img_debug.h>
#include <image_transport/image_transport.h>
#include <message_filters/subscriber.h>
#include <uart_process_2/uart_send.h>
#include <uart_process_2/uart_receive.h>
#include <cv_bridge/cv_bridge.h>
#include "EulerAngle.h"
#include "coord_solver.hpp"

using namespace std;
using namespace cv;

const float CAMERA_FOCUS = 60;
const float im_real_weights = 3.75;
const double limit_pitch_angle_val = 20;
const double limit_yaw_angle_val = 20;
const double distance_ = 2;

#define CLOCKWISE true;
#define COUNTERCLOCKWISE false;

enum class IdentityColor {
	IDENTITY_RED, IDENTITY_BLUE
};

class Buff{
private:
    Mat video1, video2;

    vector<Point2d> points;
    Point2d box_center = Point2d(0,0);

    int box_area = 0xFFFF;
    double last_angle = 0xFFFF;
    bool direction = true;//true为顺时针
    bool windmill_spd_mode = true;
    int frame = 0;

    Mat element1 = getStructuringElement(MORPH_RECT, Size(5, 5));//开运算内核
    Mat element2 = getStructuringElement(MORPH_RECT, Size(27, 27));//闭运算内核

    float time_delay = 0.2;
    double angle_offset = (0.14+0.001) * CV_PI;//(At Speed Of 25m/s)

    double timestamp;
public:
    Buff(IdentityColor);
    //~Buff();
    Buff& operator <<(cv::Mat&);

    IdentityColor targetColor;				// 目标颜色

	ros::Publisher debugImagePublisher;
	ros::Publisher uartPublisher;

	uart_process_2::uart_send uartSent;			// 串口发送数据
	uart_process_2::uart_receive uartReceive;	// 串口接受数据

    bool disabled = false;

    void update(const uart_process_2::uart_receive &receive);
    double get_cicrle_angle(Point c,double r,Point p);
    double get_distance(Point p1,Point p2);
    double perdict_angle(double angle,bool direction,bool windmill_spd_mode);
    EulerAngle getAngle(cv::Point center,cv::Point dest_point);
    void targetTo(const EulerAngle& currentAngle, double distance, bool hasTarget, int attackFlag, int predictLatency = 0);

    CoordSolver coordsolver;

};

/*Buff::Buff(){
}

Buff::~Buff(){
}*/
