#include "modules/control/submodules/lat_lon_controller_submodule.h"

int main(int argc, char *argv[])
{
    ACHECK(1 < 3) << "STARTING" << CRLF;
    AINFO << "STARTING" <<CRLF;
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::control::LatLonControllerSubmodule>());
    rclcpp::shutdown();
    return 0;    
}
