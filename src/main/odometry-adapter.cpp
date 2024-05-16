#include "component/odometry-adapter.h"
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::drivers::adapter::OdometryAdapterComponent>());
    rclcpp::shutdown();
    return 0;    
}