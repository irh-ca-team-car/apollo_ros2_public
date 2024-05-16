#pragma once
#include "apollo_msgs/msg/apolloprediction_features.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionFeatures &msg) ;
    ApollopredictionFeatures from_json_ApollopredictionFeatures (nlohmann::json obj) ;
    template <>
    ApollopredictionFeatures from_json<ApollopredictionFeatures>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionFeatures &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionFeatures & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionFeatures & dt);
}
