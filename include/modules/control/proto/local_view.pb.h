#pragma once
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/control/proto/pad_msg.pb.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/planning/proto/planning.pb.h"
#include "apollo_msgs/msg/apollocontrol_local_view.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_local_view.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolLocalView LocalView;
}