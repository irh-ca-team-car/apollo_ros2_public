#pragma once
#include "modules/drivers/canbus/proto/can_card_parameter.pb.h"
#include "apollo_msgs/msg/apollodriversultrasonic_radar_can_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversultrasonic_radar_can_conf.hpp"
namespace apollo::drivers::ultrasonic_radar{
	typedef apollo_msgs::msg::ApollodriversultrasonicRadarCanConf CanConf;
}
#include "apollo_msgs/msg/apollodriversultrasonic_radar_ultrasonic_radar_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversultrasonic_radar_ultrasonic_radar_conf.hpp"
namespace apollo::drivers::ultrasonic_radar{
	typedef apollo_msgs::msg::ApollodriversultrasonicRadarUltrasonicRadarConf UltrasonicRadarConf;
}