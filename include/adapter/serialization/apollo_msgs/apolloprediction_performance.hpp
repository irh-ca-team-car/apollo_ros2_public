#pragma once
#include "apollo_msgs/msg/apolloprediction_performance.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPerformance &msg) ;
    ApollopredictionPerformance from_json_ApollopredictionPerformance (nlohmann::json obj) ;
    template <>
    ApollopredictionPerformance from_json<ApollopredictionPerformance>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPerformance &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPerformance & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPerformance & dt);
}
