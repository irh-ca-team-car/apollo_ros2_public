#pragma once
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/control/proto/pad_msg.pb.h"
#include "modules/control/proto/lat_controller_conf.pb.h"
#include "modules/control/proto/lon_controller_conf.pb.h"
#include "modules/control/proto/mpc_controller_conf.pb.h"
#include "apollo_msgs/msg/apollocontrol_control_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_control_conf.hpp"
namespace apollo::control::ControlConf{
	enum ControllerType {
		LAT_CONTROLLER = 0,
		LON_CONTROLLER = 1,
		MPC_CONTROLLER = 2
	};
	std::string ControllerType_Name(ControllerType val);
}