#pragma once
#include "modules/control/proto/gain_scheduler_conf.pb.h"
#include "modules/control/proto/leadlag_conf.pb.h"
#include "modules/control/proto/mrac_conf.pb.h"
#include "apollo_msgs/msg/apollocontrol_lat_controller_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_lat_controller_conf.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolLatControllerConf LatControllerConf;
}