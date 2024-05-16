#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_obstacle_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_sl_boundary.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_decision_tag.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalObstacleDebug &msg) ;
    ApolloplanningInternalObstacleDebug from_json_ApolloplanningInternalObstacleDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalObstacleDebug from_json<ApolloplanningInternalObstacleDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalObstacleDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalObstacleDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalObstacleDebug & dt);
}
