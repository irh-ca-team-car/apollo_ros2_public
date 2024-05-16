#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/modulesteleopdaemon_daemon_cmd.hpp"
#include "adapter/serialization/apollo_msgs/modulesteleopdaemon_daemon_cmd.hpp"
namespace modules::teleop::daemon{
	typedef apollo_msgs::msg::ModulesteleopdaemonDaemonCmd DaemonCmd;
}