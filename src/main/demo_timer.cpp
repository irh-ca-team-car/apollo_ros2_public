#include "component/demo_timer.h"

 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DemoTimerComponent>());
    rclcpp::shutdown();
    return 0;    
}