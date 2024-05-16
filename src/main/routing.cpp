#include "component/routing.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::routing::RoutingComponent>());
    rclcpp::shutdown();
    return 0;    
}