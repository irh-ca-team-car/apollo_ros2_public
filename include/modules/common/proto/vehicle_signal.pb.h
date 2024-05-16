#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_signal.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_signal.hpp"
namespace apollo::common::VehicleSignal{
	enum TurnSignal {
		TURN_NONE = 0,
		TURN_LEFT = 1,
		TURN_RIGHT = 2
	};
}