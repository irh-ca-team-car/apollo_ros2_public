#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/perception/proto/perception_camera.pb.h"
#include "apollo_msgs/msg/apolloperception_perception_lanes.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_perception_lanes.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionPerceptionLanes PerceptionLanes;
}