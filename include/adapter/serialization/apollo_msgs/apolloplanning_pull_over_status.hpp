#pragma once
#include "apollo_msgs/msg/apolloplanning_pull_over_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPullOverStatus &msg) ;
    ApolloplanningPullOverStatus from_json_ApolloplanningPullOverStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningPullOverStatus from_json<ApolloplanningPullOverStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPullOverStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPullOverStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPullOverStatus & dt);
}
