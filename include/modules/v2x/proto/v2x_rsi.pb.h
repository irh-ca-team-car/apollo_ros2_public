#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollov2x_rsi_point.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_rsi_point.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xRsiPoint RsiPoint;
}
#include "apollo_msgs/msg/apollov2x_rsi_msg.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_rsi_msg.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xRsiMsg RsiMsg;
}