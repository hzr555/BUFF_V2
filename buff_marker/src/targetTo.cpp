#include <buff_marker/buff.h>
#include <message_filters/subscriber.h>
//#include <uart_process_2/uart_send.h>
#include <gimbal_msgs/msg/gimbal_control.hpp>
#include <gimbal_msgs/msg/gimbal_status.hpp>

using namespace sensor_msgs;
using namespace message_filters;

namespace buff_{
float toFixed(double in) {
    float result = (int)(in * 100);
    return result / 100;
}
void Buff::targetTo(const EulerAngle& currentAngle, double distance, bool hasTarget, int flag) {
    //uart_process_2::uart_send send_msg
    gimbal_msgs::msg::GimbalControl send_msg;
    send_msg.yaw = toFixed(currentAngle.yaw);
    send_msg.pitch = toFixed(currentAngle.pitch);
    send_msg.distance = distance;
    send_msg.time = hasTarget;
    send_msg.flag = 0x01;
    pub_gimbal_control_->publish(send_msg);
    //this->gimbal_Send = send_msg;
}
}