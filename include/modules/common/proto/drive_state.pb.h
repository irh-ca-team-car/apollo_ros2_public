#pragma once
#include "apollo_msgs/msg/apollocommon_engage_advice.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_engage_advice.hpp"
namespace apollo::common::EngageAdvice{
	enum Advice {
		UNKNOWN = 0,
		DISALLOW_ENGAGE = 1,
		READY_TO_ENGAGE = 2,
		KEEP_ENGAGED = 3,
		PREPARE_DISENGAGE = 4
	};
}