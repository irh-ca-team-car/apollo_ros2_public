#pragma once
#include "modules/common/proto/error_code.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollodrivers_radar_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_radar_obstacle.hpp"
#include "apollo_msgs/msg/apollodrivers_radar_obstacles.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_radar_obstacles.hpp"
namespace apollo::drivers::RadarObstacle{
	enum Status {
		NO_TARGET = 0,
		NEW_TARGET = 1,
		NEW_UPDATED_TARGET = 2,
		UPDATED_TARGET = 3,
		COASTED_TARGET = 4,
		MERGED_TARGET = 5,
		INVALID_COASTED_TARGET = 6,
		NEW_COASTED_TARGET = 7
	};
}
namespace apollo::drivers::RadarObstacle{
	enum MovingStatus {
		STATIONARY = 0,
		NEARING = 1,
		AWAYING = 2,
		NONE = 3
	};
}