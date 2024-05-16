#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodrivers_point_xyzit.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_point_xyzit.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversPointXYZIT PointXYZIT;
}
#include "apollo_msgs/msg/apollodrivers_point_cloud.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_point_cloud.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversPointCloud PointCloud;
}