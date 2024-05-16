#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollocontrol_input_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_input_debug.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolInputDebug InputDebug;
}