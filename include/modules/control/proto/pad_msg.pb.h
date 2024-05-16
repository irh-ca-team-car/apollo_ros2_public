#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/canbus/proto/chassis.pb.h"
#include "apollo_msgs/msg/apollocontrol_pad_message.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_pad_message.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolPadMessage PadMessage;
}
namespace apollo::control{
	enum DrivingAction {
		STOP = 0,
		START = 1,
		RESET = 2
	};
}