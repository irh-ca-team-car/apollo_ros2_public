#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/modulesteleopdaemon_daemon_rpt.hpp"
#include "adapter/serialization/apollo_msgs/modulesteleopdaemon_daemon_rpt.hpp"
namespace modules::teleop::daemon{
	typedef apollo_msgs::msg::ModulesteleopdaemonDaemonRpt DaemonRpt;
}