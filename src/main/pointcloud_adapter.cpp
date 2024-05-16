#include "component/pointcloud_adapter.h"
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::drivers::adapter::PointCloudAdapterComponent>());
    rclcpp::shutdown();
    return 0;    
}