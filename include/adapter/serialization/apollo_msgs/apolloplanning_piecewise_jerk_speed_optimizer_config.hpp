#pragma once
#include "apollo_msgs/msg/apolloplanning_piecewise_jerk_speed_optimizer_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPiecewiseJerkSpeedOptimizerConfig &msg) ;
    ApolloplanningPiecewiseJerkSpeedOptimizerConfig from_json_ApolloplanningPiecewiseJerkSpeedOptimizerConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPiecewiseJerkSpeedOptimizerConfig from_json<ApolloplanningPiecewiseJerkSpeedOptimizerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPiecewiseJerkSpeedOptimizerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPiecewiseJerkSpeedOptimizerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPiecewiseJerkSpeedOptimizerConfig & dt);
}
