#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_st_graph_kernel_cuise_ref.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSTGraphKernelCuiseRef &msg) ;
    ApolloplanningInternalSTGraphKernelCuiseRef from_json_ApolloplanningInternalSTGraphKernelCuiseRef (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalSTGraphKernelCuiseRef from_json<ApolloplanningInternalSTGraphKernelCuiseRef>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSTGraphKernelCuiseRef &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSTGraphKernelCuiseRef & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSTGraphKernelCuiseRef & dt);
}
