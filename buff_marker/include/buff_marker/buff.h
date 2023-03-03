#include <bits/stdc++.h>
#include <opencv4/opencv2/opencv.hpp>
//#include <ros/ros.h>
//#include <sagitari_debug/sagitari_img_debug.h>
#include <image_transport/image_transport.hpp>
#include <message_filters/subscriber.h>
//#include <uart_process_2/uart_send.h>
//#include <uart_process_2/uart_receive.h>
#include <cv_bridge/cv_bridge.h>
#include "EulerAngle.h"
#include "gimbal_msgs/msg/gimbal_control.hpp"
#include <gimbal_msgs/msg/gimbal_status.hpp>
#include <debug_msgs/msg/sagitari_debug.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <rclcpp/rclcpp.hpp>


using namespace std;
using namespace cv;
namespace buff_{
const float CAMERA_FOCUS = 60;
const float im_real_weights = 3.75;
const double limit_yaw_angle_val = 40;
const double limit_pitch_angle_val = 20;
const double distance_ = 2;

#define CLOCKWISE true;
#define COUNTERCLOCKWISE false;

enum class IdentityColor {
	IDENTITY_RED, IDENTITY_BLUE
};

class Buff : public rclcpp::Node{
private:
    bool c_is_lost = false;
    Point2d c_last;

    Mat video1, video2;

    vector<Point2d> points;
    Point2d box_center = Point2d(0,0);

    int box_area = 0xFFFF;
    double last_angle = 0xFFFF;
    double last_angle_time = 0xFFFF;
    bool direction = COUNTERCLOCKWISE;//true为顺时针
    bool windmill_spd_mode = false;
    int frame = 0;

    Mat element1 = getStructuringElement(MORPH_RECT, Size(5, 5));//开运算内核
    Mat element2 = getStructuringElement(MORPH_RECT, Size(25, 25));//闭运算内核

    float time_delay = 0.2;
    double angle_offset = (0.14+0.020) * CV_PI;//(At Speed Of 25m/s)
    //                          0.001

    double timestamp;

    double speed_arr[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int speed_cnt = 0;
public:
    //~Buff();
    Buff& operator <<(cv::Mat&);
    Buff(const rclcpp::NodeOptions & options);

    IdentityColor targetColor;				// 目标颜色

    gimbal_msgs::msg::GimbalStatus::SharedPtr msg; 

	//ros::Publisher debugImagePublisher;
	//ros::Publisher uartPublisher;

	//uart_process_2::uart_send uartSent;			// 串口发送数据
	//uart_process_2::uart_receive uartReceive;	// 串口接受数据

    rclcpp::Publisher<debug_msgs::msg::SagitariDebug>::SharedPtr debug_image_pub_;   
    
    gimbal_msgs::msg::GimbalControl::SharedPtr gimbal_Send;
    gimbal_msgs::msg::GimbalStatus::SharedPtr gimbal_Receive;

    rclcpp::Publisher<gimbal_msgs::msg::GimbalControl>::SharedPtr pub_gimbal_control_;
    image_transport::Publisher publisher;
    gimbal_msgs::msg::GimbalStatus::SharedPtr currentReceive;
        
    image_transport::Subscriber camera_raw_sub_;
    rclcpp::Subscription<gimbal_msgs::msg::GimbalStatus>::SharedPtr sub_imu_;

    void failSafe(int);
    void onGimbalMessageReceived(const gimbal_msgs::msg::GimbalStatus::SharedPtr msg);
    void onCameraRawImageReceived(const sensor_msgs::msg::Image::ConstSharedPtr &msg);
    sensor_msgs::msg::Image::UniquePtr colorImageCallback(sensor_msgs::msg::Image::UniquePtr ptr);
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr pub_image_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_img_;
    void clearScreen();

    bool disabled = false;

    void update(const gimbal_msgs::msg::GimbalStatus::SharedPtr receive);
    double get_cicrle_angle(Point c,double r,Point p);
    double get_distance(Point p1,Point p2);
    double perdict_angle(double angle,bool direction,bool windmill_spd_mode);
    EulerAngle getAngle(cv::Point center,cv::Point dest_point);
    void targetTo(const EulerAngle& currentAngle, double distance, bool hasTarget, int flag);
    double calc_speed(double time_now, double angle);

};

}

/*Buff::Buff(){
}

Buff::~Buff(){
}*/
