#pragma once
#include "modules/control/proto/calibration_table.pb.h"
#include "modules/control/proto/leadlag_conf.pb.h"
#include "modules/control/proto/pid_conf.pb.h"
#include "apollo_msgs/msg/apollocontrol_filter_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_filter_conf.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolFilterConf FilterConf;
}
#include "apollo_msgs/msg/apollocontrol_lon_controller_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_lon_controller_conf.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolLonControllerConf LonControllerConf;
}