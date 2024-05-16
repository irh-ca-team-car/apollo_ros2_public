#pragma once
#include "apollo_msgs/msg/apolloplanning_iterative_anchoring_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_fem_pos_deviation_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_speed_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningIterativeAnchoringConfig &msg) ;
    ApolloplanningIterativeAnchoringConfig from_json_ApolloplanningIterativeAnchoringConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningIterativeAnchoringConfig from_json<ApolloplanningIterativeAnchoringConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningIterativeAnchoringConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningIterativeAnchoringConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningIterativeAnchoringConfig & dt);
}
