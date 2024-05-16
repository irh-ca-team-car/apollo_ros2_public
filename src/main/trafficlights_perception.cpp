 #include "component/trafficlights_perception.h"

 int main(int argc, char *argv[])
{
    ACHECK(1 < 3) << "STARTING" << CRLF;
    AINFO << "STARTING" <<CRLF;
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::perception::onboard::TrafficLightsPerceptionComponent>());
    rclcpp::shutdown();
    return 0;
}
