#pragma once
#include "modules/control/proto/calibration_table.pb.h"
#include "modules/control/proto/gain_scheduler_conf.pb.h"
#include "apollo_msgs/msg/apollocontrol_mpc_controller_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_mpc_controller_conf.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolMPCControllerConf MPCControllerConf;
}