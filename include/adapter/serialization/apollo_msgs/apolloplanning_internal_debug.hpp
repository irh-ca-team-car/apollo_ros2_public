#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_planning_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalDebug &msg) ;
    ApolloplanningInternalDebug from_json_ApolloplanningInternalDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalDebug from_json<ApolloplanningInternalDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalDebug & dt);
}
