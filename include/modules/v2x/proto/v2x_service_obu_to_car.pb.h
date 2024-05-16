#pragma once
#include "modules/v2x/proto/v2x_obu_traffic_light.pb.h"
#include "modules/v2x/proto/v2x_monitor.pb.h"
#include "modules/v2x/proto/v2x_obu_rsi.pb.h"
#include "modules/v2x/proto/v2x_obstacles.pb.h"
#include "apollo_msgs/msg/apollov2x_status_response.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_status_response.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xStatusResponse StatusResponse;
}