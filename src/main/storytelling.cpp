#include "component/storytelling.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::storytelling::Storytelling>());
    rclcpp::shutdown();
    
    return 0;    
}