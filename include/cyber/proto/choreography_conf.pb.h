#pragma once
#include "apollo_msgs/msg/apollocyberproto_choreography_task.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_choreography_task.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChoreographyTask ChoreographyTask;
}
#include "apollo_msgs/msg/apollocyberproto_choreography_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_choreography_conf.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChoreographyConf ChoreographyConf;
}