 #include "component/camera.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::drivers::camera::CameraComponent>());
    rclcpp::shutdown();
    return 0;    
}