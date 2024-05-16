#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodrivers_ultrasonic.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_ultrasonic.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversUltrasonic Ultrasonic;
}