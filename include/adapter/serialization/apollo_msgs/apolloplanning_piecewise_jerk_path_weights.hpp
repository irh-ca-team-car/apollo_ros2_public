#pragma once
#include "apollo_msgs/msg/apolloplanning_piecewise_jerk_path_weights.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPiecewiseJerkPathWeights &msg) ;
    ApolloplanningPiecewiseJerkPathWeights from_json_ApolloplanningPiecewiseJerkPathWeights (nlohmann::json obj) ;
    template <>
    ApolloplanningPiecewiseJerkPathWeights from_json<ApolloplanningPiecewiseJerkPathWeights>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPiecewiseJerkPathWeights &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPiecewiseJerkPathWeights & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPiecewiseJerkPathWeights & dt);
}
