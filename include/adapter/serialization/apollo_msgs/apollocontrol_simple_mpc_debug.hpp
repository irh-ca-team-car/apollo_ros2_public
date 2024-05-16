#pragma once
#include "apollo_msgs/msg/apollocontrol_simple_mpc_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolSimpleMPCDebug &msg) ;
    ApollocontrolSimpleMPCDebug from_json_ApollocontrolSimpleMPCDebug (nlohmann::json obj) ;
    template <>
    ApollocontrolSimpleMPCDebug from_json<ApollocontrolSimpleMPCDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolSimpleMPCDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolSimpleMPCDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolSimpleMPCDebug & dt);
}
