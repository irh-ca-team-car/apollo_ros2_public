#pragma once
#include "cyber/proto/classic_conf.pb.h"
#include "cyber/proto/choreography_conf.pb.h"
#include "apollo_msgs/msg/apollocyberproto_inner_thread.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_inner_thread.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoInnerThread InnerThread;
}
#include "apollo_msgs/msg/apollocyberproto_scheduler_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_scheduler_conf.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoSchedulerConf SchedulerConf;
}