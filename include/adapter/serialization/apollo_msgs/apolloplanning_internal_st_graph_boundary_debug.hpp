#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_st_graph_boundary_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_speed_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalStGraphBoundaryDebug &msg) ;
    ApolloplanningInternalStGraphBoundaryDebug from_json_ApolloplanningInternalStGraphBoundaryDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalStGraphBoundaryDebug from_json<ApolloplanningInternalStGraphBoundaryDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalStGraphBoundaryDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalStGraphBoundaryDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalStGraphBoundaryDebug & dt);
}
