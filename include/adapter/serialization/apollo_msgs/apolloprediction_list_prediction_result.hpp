#pragma once
#include "apollo_msgs/msg/apolloprediction_list_prediction_result.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionListPredictionResult &msg) ;
    ApollopredictionListPredictionResult from_json_ApollopredictionListPredictionResult (nlohmann::json obj) ;
    template <>
    ApollopredictionListPredictionResult from_json<ApollopredictionListPredictionResult>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionListPredictionResult &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionListPredictionResult & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionListPredictionResult & dt);
}
