#include "component/multiargs.h"
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MultiArgsComponent>());
    rclcpp::shutdown();
    return 0;    
}