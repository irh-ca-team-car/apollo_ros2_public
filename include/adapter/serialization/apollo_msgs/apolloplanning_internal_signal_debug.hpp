#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_signal_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSignalDebug &msg) ;
    ApolloplanningInternalSignalDebug from_json_ApolloplanningInternalSignalDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalSignalDebug from_json<ApolloplanningInternalSignalDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSignalDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSignalDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSignalDebug & dt);
}
