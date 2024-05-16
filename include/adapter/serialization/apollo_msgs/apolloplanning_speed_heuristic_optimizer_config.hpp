#pragma once
#include "apollo_msgs/msg/apolloplanning_speed_heuristic_optimizer_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_dp_st_speed_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSpeedHeuristicOptimizerConfig &msg) ;
    ApolloplanningSpeedHeuristicOptimizerConfig from_json_ApolloplanningSpeedHeuristicOptimizerConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningSpeedHeuristicOptimizerConfig from_json<ApolloplanningSpeedHeuristicOptimizerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSpeedHeuristicOptimizerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSpeedHeuristicOptimizerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSpeedHeuristicOptimizerConfig & dt);
}
