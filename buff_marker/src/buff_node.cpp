#include <buff_marker/buff.h>

using namespace std::chrono_literals;

bool debug = false;
// image_transport::Publisher publisher;
// gimbal_msgs::msg::GimbalStatus currentReceive;
// gimbal_msgs::msg::GimbalStatus::SharedPtr msg;

cv::Mat imageNoSignal;
namespace buff_{
int encoding2mat_type(const std::string & encoding){
    if (encoding == "mono8") {
        return CV_8UC1;
    } else if (encoding == "bgr8") {
        return CV_8UC3;
    } else if (encoding == "mono16") {
        return CV_16SC1;
    } else if (encoding == "rgba8") {
        return CV_8UC4;
    } else if (encoding == "bgra8") {
        return CV_8UC4;
    } else if (encoding == "32FC1") {
        return CV_32FC1;
    } else if (encoding == "rgb8") {
        return CV_8UC3;
    } else if (encoding == "yuv422") {
        return CV_8UC2;
    } else {
        throw std::runtime_error("Unsupported encoding type");
    }
}
Buff::Buff(const rclcpp::NodeOptions & options)
: Node("buff_", options)
{
	this->targetColor = IdentityColor::IDENTITY_BLUE;
	// signal(SIGINT, void (Buff::failSafe)(int));
	// signal(SIGABRT, void (Buff::failSafe)(int));
	// signal(SIGINT, std::bind(&BuffNode::failSafe,  std::placeholders::_1));
	// signal(SIGABRT, std::bind(&BuffNode::failSafe, this, std::placeholders::_1));
	RCLCPP_INFO(this->get_logger(), "Start!");
	debug = true;

	
	this->pub_gimbal_control_ = create_publisher<gimbal_msgs::msg::GimbalControl>("gimbal/control", 1);
	this->debug_image_pub_ = create_publisher<debug_msgs::msg::SagitariDebug>("Sagitari/debugImage", 1);

	// camera_raw_sub_ = image_transport::create_subscription(
	// 	this, "image_raw", std::bind(&Buff::onCameraRawImageReceived, this, std::placeholders::_1), 
	// 	"raw");

	sub_imu_ = create_subscription<gimbal_msgs::msg::GimbalStatus>(
		"/gimbal/status", 10, std::bind(&Buff::onGimbalMessageReceived, this, std::placeholders::_1));
	rclcpp::SensorDataQoS qos;
	this->pub_image_ = this->create_publisher<sensor_msgs::msg::Image>("image_raw/pipeline/detector_to_decsion", rclcpp::SensorDataQoS());
	std::weak_ptr<std::remove_pointer<decltype(this->pub_image_.get())>::type> captured_pub = pub_image_;
    sub_img_ = create_subscription<sensor_msgs::msg::Image>(
        "image_raw/pipeline/camera_to_detector",
        qos,
        [captured_pub, this](sensor_msgs::msg::Image::UniquePtr msg) {
                auto pub_ptr = captured_pub.lock();
                if (!pub_ptr) {
                    return;
                }
                pub_ptr->publish(std::move(this->colorImageCallback(std::move(msg))));    // Publish it along.
            }
    );
}

void Buff::clearScreen()
{
	cout << "\033[2J\033[1;1H";
}

void Buff::onCameraRawImageReceived(const sensor_msgs::msg::Image::ConstSharedPtr &msg)
{
	/*if(sagitari.disabled) {
		sagitari.cancelTracking(); // Keep marking ending for sagitari to prevent unfinished <<
		if(imageNoSignal.empty()) {
			imageNoSignal = cv::imread("nosignal.jpg");
		}
		sagitari.sendDebugImage("Tracking", imageNoSignal);
	} else {*/
	auto start = std::chrono::system_clock::now();
	// buff.gimbal_Receive = currentReceive;
	if(debug) std::cerr << "\033[41;37m debug mode \033[0m" << std::endl;
	(*this) << cv_bridge::toCvCopy(msg, "bgr8")->image;

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cerr << " - Timing: Total time elapsed: " << std::to_string(duration) << "ms." << std::endl;
	clearScreen();
	//}
}
sensor_msgs::msg::Image::UniquePtr Buff::colorImageCallback(sensor_msgs::msg::Image::UniquePtr ptr){
    cv::Mat frame(
        ptr->height, ptr->width,
        encoding2mat_type(ptr->encoding),
        ptr->data.data()
    );

	auto start = std::chrono::system_clock::now();
	// buff.gimbal_Receive = currentReceive;
	if(debug) std::cerr << "\033[41;37m debug mode \033[0m" << std::endl;
	(*this) << frame;

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cerr << " - Timing: Total time elapsed: " << std::to_string(duration) << "ms." << std::endl;
	clearScreen();

	return std::move(ptr);
}
void Buff::onGimbalMessageReceived(const gimbal_msgs::msg::GimbalStatus::SharedPtr msg)
{
	// currentReceive = msg;
	this->update(msg);
}

void Buff::failSafe(int)
{
	std::cerr << "[FailSafe] I'm dying." << std::endl;
	/*const EulerAngle failSafeAngle = {0, 0};
	sagitari.targetTo(failSafeAngle, failSafeAngle, 0, false, 0);*/
}


}