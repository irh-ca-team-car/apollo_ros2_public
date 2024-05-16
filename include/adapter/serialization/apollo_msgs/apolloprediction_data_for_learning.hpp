#pragma once
#include "apollo_msgs/msg/apolloprediction_data_for_learning.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionDataForLearning &msg) ;
    ApollopredictionDataForLearning from_json_ApollopredictionDataForLearning (nlohmann::json obj) ;
    template <>
    ApollopredictionDataForLearning from_json<ApollopredictionDataForLearning>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionDataForLearning &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionDataForLearning & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionDataForLearning & dt);
}
