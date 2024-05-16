#include "component/task_manager.h"
 
 std::shared_ptr<apollo::task_manager::TaskManagerComponent> node__;
 int main(int argc, char *argv[])
{
    ACHECK(1 < 3) << "STARTING" << CRLF;
    AINFO << "STARTING" <<CRLF;
    rclcpp::init(argc, argv);
    node__ = std::make_shared<apollo::task_manager::TaskManagerComponent>();
    rclcpp::spin(node__);
    rclcpp::shutdown();
    return 0;
}
