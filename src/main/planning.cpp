 #include "component/planning.h"

 int main(int argc, char *argv[])
{
    AINFO << "STARTING" <<CRLF;
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::planning::PlanningComponent>());
    rclcpp::shutdown();
    return 0;    
}