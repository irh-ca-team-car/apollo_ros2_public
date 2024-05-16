#pragma once
#include "apollo_msgs/msg/apolloplanning_prediction_trajectory_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_trajectory_point_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPredictionTrajectoryFeature &msg) ;
    ApolloplanningPredictionTrajectoryFeature from_json_ApolloplanningPredictionTrajectoryFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningPredictionTrajectoryFeature from_json<ApolloplanningPredictionTrajectoryFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPredictionTrajectoryFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPredictionTrajectoryFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPredictionTrajectoryFeature & dt);
}
