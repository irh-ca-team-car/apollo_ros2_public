#include "component/adc-trajectory-adapter.h"
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::drivers::adapter::ADCTrajectoryAdapterComponent>());
    rclcpp::shutdown();
    return 0;    
}