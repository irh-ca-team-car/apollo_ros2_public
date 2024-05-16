#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_dp_poly_graph_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_sample_layer_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_sl_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalDpPolyGraphDebug &msg) ;
    ApolloplanningInternalDpPolyGraphDebug from_json_ApolloplanningInternalDpPolyGraphDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalDpPolyGraphDebug from_json<ApolloplanningInternalDpPolyGraphDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalDpPolyGraphDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalDpPolyGraphDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalDpPolyGraphDebug & dt);
}
