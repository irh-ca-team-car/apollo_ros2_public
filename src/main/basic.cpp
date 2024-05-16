 #include "component/basic.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BasicComponent>());
    rclcpp::shutdown();
    return 0;    
}