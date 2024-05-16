#pragma once
#include "apollo_msgs/msg/apollocontrol_gain_scheduler.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_gain_scheduler.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolGainScheduler GainScheduler;
}
#include "apollo_msgs/msg/apollocontrol_gain_scheduler_info.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_gain_scheduler_info.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolGainSchedulerInfo GainSchedulerInfo;
}