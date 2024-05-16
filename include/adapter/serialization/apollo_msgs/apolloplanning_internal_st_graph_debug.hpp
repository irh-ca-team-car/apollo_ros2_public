#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_st_graph_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_boundary_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_speed_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_speed_constraint.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_kernel_cuise_ref.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_kernel_follow_ref.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSTGraphDebug &msg) ;
    ApolloplanningInternalSTGraphDebug from_json_ApolloplanningInternalSTGraphDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalSTGraphDebug from_json<ApolloplanningInternalSTGraphDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSTGraphDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSTGraphDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSTGraphDebug & dt);
}
