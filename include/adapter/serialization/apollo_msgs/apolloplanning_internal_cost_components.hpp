#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_cost_components.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalCostComponents &msg) ;
    ApolloplanningInternalCostComponents from_json_ApolloplanningInternalCostComponents (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalCostComponents from_json<ApolloplanningInternalCostComponents>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalCostComponents &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalCostComponents & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalCostComponents & dt);
}
