 #include "component/camera-adapter.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::drivers::camera::CameraAdapterComponent>());
    rclcpp::shutdown();
    return 0;    
}