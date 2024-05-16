#pragma once
#include "modules/common/proto/error_code.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollothird_party_perception_radar_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apollothird_party_perception_radar_obstacle.hpp"
namespace apollo::third_party_perception{
	typedef apollo_msgs::msg::ApollothirdPartyPerceptionRadarObstacle RadarObstacle;
}
#include "apollo_msgs/msg/apollothird_party_perception_radar_obstacles.hpp"
#include "adapter/serialization/apollo_msgs/apollothird_party_perception_radar_obstacles.hpp"