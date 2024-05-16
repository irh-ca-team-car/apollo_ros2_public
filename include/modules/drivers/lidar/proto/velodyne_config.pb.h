#pragma once
#include "modules/drivers/lidar/proto/velodyne.pb.h"
#include "apollo_msgs/msg/apollodriversvelodyne_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_config.hpp"
namespace apollo::drivers::velodyne{
	typedef apollo_msgs::msg::ApollodriversvelodyneConfig Config;
}
#include "apollo_msgs/msg/apollodriversvelodyne_fusion_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_fusion_config.hpp"
namespace apollo::drivers::velodyne{
	typedef apollo_msgs::msg::ApollodriversvelodyneFusionConfig FusionConfig;
}
#include "apollo_msgs/msg/apollodriversvelodyne_compensator_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_compensator_config.hpp"
namespace apollo::drivers::velodyne{
	typedef apollo_msgs::msg::ApollodriversvelodyneCompensatorConfig CompensatorConfig;
}