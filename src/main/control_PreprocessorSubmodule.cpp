#include "modules/control/submodules/preprocessor_submodule.h"

int main(int argc, char *argv[])
{
    ACHECK(1 < 3) << "STARTING" << CRLF;
    AINFO << "STARTING" <<CRLF;
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::control::PreprocessorSubmodule>());
    rclcpp::shutdown();
    return 0;    
}
