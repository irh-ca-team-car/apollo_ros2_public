#pragma once
#include "modules/drivers/lidar/proto/hesai_config.pb.h"
#include "modules/drivers/lidar/proto/velodyne_config.pb.h"
#include "modules/drivers/lidar/proto/lidar_parameter.pb.h"
#include "modules/drivers/lidar/proto/robosense_config.pb.h"
#include "apollo_msgs/msg/apollodriverslidarconfig.hpp"
#include "adapter/serialization/apollo_msgs/apollodriverslidarconfig.hpp"
namespace apollo::drivers::lidar{
	typedef apollo_msgs::msg::Apollodriverslidarconfig config;
}