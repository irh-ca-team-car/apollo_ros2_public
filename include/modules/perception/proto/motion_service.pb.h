#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apolloperception_motion_type.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_motion_type.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionMotionType MotionType;
}
#include "apollo_msgs/msg/apolloperception_vehicle_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_vehicle_status.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionVehicleStatus VehicleStatus;
}
#include "apollo_msgs/msg/apolloperception_motion_service.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_motion_service.hpp"
namespace apollo::perception
{
	typedef apollo_msgs::msg::ApolloperceptionMotionService Motion_Service;
}