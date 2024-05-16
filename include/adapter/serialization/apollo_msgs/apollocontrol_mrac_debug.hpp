#pragma once
#include "apollo_msgs/msg/apollocontrol_mrac_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontrol_mrac_adaptive_gain.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolMracDebug &msg) ;
    ApollocontrolMracDebug from_json_ApollocontrolMracDebug (nlohmann::json obj) ;
    template <>
    ApollocontrolMracDebug from_json<ApollocontrolMracDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolMracDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolMracDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolMracDebug & dt);
}
