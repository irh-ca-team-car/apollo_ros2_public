#pragma once
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/control/proto/pad_msg.pb.h"
#include "apollo_msgs/msg/apollocontrol_control_common_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_control_common_conf.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolControlCommonConf ControlCommonConf;
}