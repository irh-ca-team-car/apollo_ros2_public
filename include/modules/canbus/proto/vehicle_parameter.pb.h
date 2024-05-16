#pragma once
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/common/configs/proto/vehicle_config.pb.h"
#include "apollo_msgs/msg/apollocanbus_vehicle_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_parameter.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVehicleParameter VehicleParameter;
}