#pragma once
#include "cyber/proto/scheduler_conf.pb.h"
#include "cyber/proto/transport_conf.pb.h"
#include "cyber/proto/run_mode_conf.pb.h"
#include "cyber/proto/perf_conf.pb.h"
#include "apollo_msgs/msg/apollocyberproto_cyber_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_cyber_config.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoCyberConfig CyberConfig;
}