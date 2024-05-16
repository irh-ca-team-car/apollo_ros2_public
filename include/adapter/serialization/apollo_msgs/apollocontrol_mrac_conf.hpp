#pragma once
#include "apollo_msgs/msg/apollocontrol_mrac_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolMracConf &msg) ;
    ApollocontrolMracConf from_json_ApollocontrolMracConf (nlohmann::json obj) ;
    template <>
    ApollocontrolMracConf from_json<ApollocontrolMracConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolMracConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolMracConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolMracConf & dt);
}
