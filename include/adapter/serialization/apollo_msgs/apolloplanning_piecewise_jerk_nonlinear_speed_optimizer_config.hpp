#pragma once
#include "apollo_msgs/msg/apolloplanning_piecewise_jerk_nonlinear_speed_optimizer_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig &msg) ;
    ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig from_json_ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig from_json<ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig & dt);
}
