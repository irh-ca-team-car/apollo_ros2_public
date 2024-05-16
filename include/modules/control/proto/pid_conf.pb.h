#pragma once
#include "apollo_msgs/msg/apollocontrol_pid_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_pid_conf.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolPidConf PidConf;
}