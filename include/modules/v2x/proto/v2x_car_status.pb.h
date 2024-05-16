#pragma once
#include "modules/localization/proto/localization.pb.h"
#include "modules/canbus/proto/chassis_detail.pb.h"
#include "modules/v2x/proto/v2x_junction.pb.h"
#include "apollo_msgs/msg/apollov2x_car_status.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_car_status.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xCarStatus CarStatus;
}