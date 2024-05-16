#pragma once
#include "apollo_msgs/msg/apollocontrol_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontrol_simple_longitudinal_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_simple_lateral_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_input_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_simple_mpc_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolDebug &msg) ;
    ApollocontrolDebug from_json_ApollocontrolDebug (nlohmann::json obj) ;
    template <>
    ApollocontrolDebug from_json<ApollocontrolDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolDebug & dt);
}
