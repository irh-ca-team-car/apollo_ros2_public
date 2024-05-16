#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/modulesteleopmodem_modem_info.hpp"
#include "adapter/serialization/apollo_msgs/modulesteleopmodem_modem_info.hpp"
namespace modules::teleop::modem{
	typedef apollo_msgs::msg::ModulesteleopmodemModemInfo ModemInfo;
}