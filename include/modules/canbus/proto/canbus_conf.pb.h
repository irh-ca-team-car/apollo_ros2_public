#pragma once
#include "modules/drivers/canbus/proto/can_card_parameter.pb.h"
#include "modules/canbus/proto/vehicle_parameter.pb.h"
#include "apollo_msgs/msg/apollocanbus_canbus_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_canbus_conf.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusCanbusConf CanbusConf;
}