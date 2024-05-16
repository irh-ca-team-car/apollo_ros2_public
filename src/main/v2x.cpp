 #include "component/v2x_fusion.h"

 int main(int argc, char *argv[])
{
    ACHECK(1 < 3) << "STARTING" << CRLF;
    AINFO << "STARTING" <<CRLF;
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::v2x::ft::V2XFusionComponent>());
    rclcpp::shutdown();
    return 0;
}