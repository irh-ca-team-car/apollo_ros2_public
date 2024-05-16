#pragma once
#include "modules/drivers/lidar/proto/hesai.pb.h"
#include "apollo_msgs/msg/apollodrivershesai_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivershesai_config.hpp"
namespace apollo::drivers::hesai{
	typedef apollo_msgs::msg::ApollodrivershesaiConfig Config;
}