#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_pull_over_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalPullOverDebug &msg) ;
    ApolloplanningInternalPullOverDebug from_json_ApolloplanningInternalPullOverDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalPullOverDebug from_json<ApolloplanningInternalPullOverDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalPullOverDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalPullOverDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalPullOverDebug & dt);
}
