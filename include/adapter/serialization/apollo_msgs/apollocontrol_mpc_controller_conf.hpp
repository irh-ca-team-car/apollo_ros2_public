#pragma once
#include "apollo_msgs/msg/apollocontrol_mpc_controller_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontrol_gain_scheduler.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrolcalibrationtable_control_calibration_table.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolMPCControllerConf &msg) ;
    ApollocontrolMPCControllerConf from_json_ApollocontrolMPCControllerConf (nlohmann::json obj) ;
    template <>
    ApollocontrolMPCControllerConf from_json<ApollocontrolMPCControllerConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolMPCControllerConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolMPCControllerConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolMPCControllerConf & dt);
}
