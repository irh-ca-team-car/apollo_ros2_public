#include "component/ndt_localization.h"
#include "cyber/cyber.h"

int main(int argc, char *argv[])
{
    ACHECK(1 < 3) << "STARTING" << CRLF;
    AINFO << "STARTING" <<CRLF;
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::localization::ndt::NDTLocalizationComponent>());
    rclcpp::shutdown();
    return 0;    
}
