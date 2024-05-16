 #include "component/radar-adapter.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::drivers::adapter::RadarAdapterComponent>());
    rclcpp::shutdown();
    return 0;    
}