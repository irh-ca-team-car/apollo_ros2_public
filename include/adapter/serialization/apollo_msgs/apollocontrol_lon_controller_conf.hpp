#pragma once
#include "apollo_msgs/msg/apollocontrol_lon_controller_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontrol_pid_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_filter_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_leadlag_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrolcalibrationtable_control_calibration_table.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLonControllerConf &msg) ;
    ApollocontrolLonControllerConf from_json_ApollocontrolLonControllerConf (nlohmann::json obj) ;
    template <>
    ApollocontrolLonControllerConf from_json<ApollocontrolLonControllerConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLonControllerConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLonControllerConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLonControllerConf & dt);
}
