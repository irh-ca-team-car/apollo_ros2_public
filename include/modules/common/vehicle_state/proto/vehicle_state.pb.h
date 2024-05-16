#pragma once
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/localization/proto/pose.pb.h"
#include "apollo_msgs/msg/apollocommon_vehicle_state.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_state.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonVehicleState VehicleState;
}