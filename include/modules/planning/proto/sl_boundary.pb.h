#pragma once
#include "modules/common/proto/pnc_point.pb.h"
#include "apollo_msgs/msg/apolloplanning_sl_boundary.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_sl_boundary.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningSLBoundary SLBoundary;
}