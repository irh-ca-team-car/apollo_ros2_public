#include "component/online_visualizer.h"
#include "cyber/cyber.h"

int main(int argc, char *argv[])
{
    ACHECK(1 < 3) << "STARTING" << CRLF;
    AINFO << "STARTING" <<CRLF;
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::localization::msf::OnlineVisualizerComponent>());
    rclcpp::shutdown();
    return 0;    
}
