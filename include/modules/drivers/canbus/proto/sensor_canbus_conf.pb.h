#pragma once
#include "modules/drivers/canbus/proto/can_card_parameter.pb.h"
#include "apollo_msgs/msg/apollodriverscanbus_sensor_canbus_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriverscanbus_sensor_canbus_conf.hpp"
namespace apollo::drivers::canbus{
	typedef apollo_msgs::msg::ApollodriverscanbusSensorCanbusConf SensorCanbusConf;
}