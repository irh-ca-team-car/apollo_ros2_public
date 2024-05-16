#include "component/drivekit.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DrivekitComponent>());
    rclcpp::shutdown();
    return 0;    
}