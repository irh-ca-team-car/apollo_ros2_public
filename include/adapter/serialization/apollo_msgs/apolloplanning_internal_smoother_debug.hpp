#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_smoother_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSmootherDebug &msg) ;
    ApolloplanningInternalSmootherDebug from_json_ApolloplanningInternalSmootherDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalSmootherDebug from_json<ApolloplanningInternalSmootherDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSmootherDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSmootherDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSmootherDebug & dt);
}
