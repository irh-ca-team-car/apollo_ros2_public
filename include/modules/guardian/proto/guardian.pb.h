#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/control/proto/control_cmd.pb.h"
#include "apollo_msgs/msg/apolloguardian_guardian_command.hpp"
#include "adapter/serialization/apollo_msgs/apolloguardian_guardian_command.hpp"
namespace apollo::guardian{
	typedef apollo_msgs::msg::ApolloguardianGuardianCommand GuardianCommand;
}