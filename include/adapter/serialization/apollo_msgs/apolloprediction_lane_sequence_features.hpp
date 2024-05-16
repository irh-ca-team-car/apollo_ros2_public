#pragma once
#include "apollo_msgs/msg/apolloprediction_lane_sequence_features.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneSequenceFeatures &msg) ;
    ApollopredictionLaneSequenceFeatures from_json_ApollopredictionLaneSequenceFeatures (nlohmann::json obj) ;
    template <>
    ApollopredictionLaneSequenceFeatures from_json<ApollopredictionLaneSequenceFeatures>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneSequenceFeatures &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneSequenceFeatures & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneSequenceFeatures & dt);
}
