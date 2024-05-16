#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_st_graph_kernel_follow_ref.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSTGraphKernelFollowRef &msg) ;
    ApolloplanningInternalSTGraphKernelFollowRef from_json_ApolloplanningInternalSTGraphKernelFollowRef (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalSTGraphKernelFollowRef from_json<ApolloplanningInternalSTGraphKernelFollowRef>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSTGraphKernelFollowRef &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSTGraphKernelFollowRef & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSTGraphKernelFollowRef & dt);
}
