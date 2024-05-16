#pragma once
#include "apollo_msgs/msg/apollocontrol_control_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontrol_lat_controller_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_lon_controller_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_mpc_controller_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolControlConf &msg) ;
    ApollocontrolControlConf from_json_ApollocontrolControlConf (nlohmann::json obj) ;
    template <>
    ApollocontrolControlConf from_json<ApollocontrolControlConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolControlConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolControlConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolControlConf & dt);
}
