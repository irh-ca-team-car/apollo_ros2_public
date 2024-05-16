#pragma once
#include "apollo_msgs/msg/apolloprediction_prediction_trajectory_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_path_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionTrajectoryPoint &msg) ;
    ApollopredictionPredictionTrajectoryPoint from_json_ApollopredictionPredictionTrajectoryPoint (nlohmann::json obj) ;
    template <>
    ApollopredictionPredictionTrajectoryPoint from_json<ApollopredictionPredictionTrajectoryPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionTrajectoryPoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionTrajectoryPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionTrajectoryPoint & dt);
}
