#pragma once
#include "apollo_msgs/msg/apolloplanning_target_lane.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTargetLane &msg) ;
    ApolloplanningTargetLane from_json_ApolloplanningTargetLane (nlohmann::json obj) ;
    template <>
    ApolloplanningTargetLane from_json<ApolloplanningTargetLane>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTargetLane &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTargetLane & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTargetLane & dt);
}
