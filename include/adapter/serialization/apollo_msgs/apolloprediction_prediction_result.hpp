#pragma once
#include "apollo_msgs/msg/apolloprediction_prediction_result.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_trajectory.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_conf.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_scenario.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionResult &msg) ;
    ApollopredictionPredictionResult from_json_ApollopredictionPredictionResult (nlohmann::json obj) ;
    template <>
    ApollopredictionPredictionResult from_json<ApollopredictionPredictionResult>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionResult &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionResult & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionResult & dt);
}
