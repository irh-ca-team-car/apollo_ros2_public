 #include "component/imu-adapter.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::drivers::adapter::IMUAdapterComponent>());
    rclcpp::shutdown();
    return 0;    
}