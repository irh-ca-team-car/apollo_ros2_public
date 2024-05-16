#pragma once
#include "apollo_msgs/msg/apolloprediction_scenario.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_scenario.hpp"
namespace apollo::prediction::Scenario{
	enum Type {
		UNKNOWN = 0,
		CRUISE = 1000,
		CRUISE_URBAN = 1001,
		CRUISE_HIGHWAY = 1002,
		JUNCTION = 2000,
		JUNCTION_TRAFFIC_LIGHT = 2001,
		JUNCTION_STOP_SIGN = 2002
	};
}