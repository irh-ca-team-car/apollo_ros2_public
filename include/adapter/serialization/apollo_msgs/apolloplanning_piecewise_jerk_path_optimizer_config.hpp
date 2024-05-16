#pragma once
#include "apollo_msgs/msg/apolloplanning_piecewise_jerk_path_optimizer_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_path_weights.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPiecewiseJerkPathOptimizerConfig &msg) ;
    ApolloplanningPiecewiseJerkPathOptimizerConfig from_json_ApolloplanningPiecewiseJerkPathOptimizerConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPiecewiseJerkPathOptimizerConfig from_json<ApolloplanningPiecewiseJerkPathOptimizerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPiecewiseJerkPathOptimizerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPiecewiseJerkPathOptimizerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPiecewiseJerkPathOptimizerConfig & dt);
}
