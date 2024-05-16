#include "component/demo.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DemoComponent>());
    rclcpp::shutdown();
    return 0;    
}