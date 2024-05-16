#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_signal_light_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_signal_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSignalLightDebug &msg) ;
    ApolloplanningInternalSignalLightDebug from_json_ApolloplanningInternalSignalLightDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalSignalLightDebug from_json<ApolloplanningInternalSignalLightDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSignalLightDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSignalLightDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSignalLightDebug & dt);
}
