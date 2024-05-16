 #include "component/relative_map.h"

 int main(int argc, char *argv[])
{
    AINFO << "STARTING" <<CRLF;
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::relative_map::RelativeMapComponent>());
    rclcpp::shutdown();
    return 0;    
}