#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apolloplanning_pad_message.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_pad_message.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPadMessage PadMessage;
}
namespace apollo::planning{
	enum DrivingAction {
		NONE = 100,
		FOLLOW = 0,
		CHANGE_LEFT = 1,
		CHANGE_RIGHT = 2,
		PULL_OVER = 3,
		STOP = 4,
		RESUME_CRUISE = 5
	};
}