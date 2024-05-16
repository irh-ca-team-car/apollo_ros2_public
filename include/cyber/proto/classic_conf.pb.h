#pragma once
#include "apollo_msgs/msg/apollocyberproto_classic_task.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_classic_task.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoClassicTask ClassicTask;
}
#include "apollo_msgs/msg/apollocyberproto_sched_group.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_sched_group.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoSchedGroup SchedGroup;
}
#include "apollo_msgs/msg/apollocyberproto_classic_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_classic_conf.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoClassicConf ClassicConf;
}