#pragma once
#include "modules/v2x/proto/v2x_car_status.pb.h"
#include "apollo_msgs/msg/apollov2x_update_status.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_update_status.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xUpdateStatus UpdateStatus;
}