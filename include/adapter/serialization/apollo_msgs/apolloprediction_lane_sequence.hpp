#pragma once
#include "apollo_msgs/msg/apolloprediction_lane_sequence.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_segment.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_path_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_nearby_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_stop_sign.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_sequence_features.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneSequence &msg) ;
    ApollopredictionLaneSequence from_json_ApollopredictionLaneSequence (nlohmann::json obj) ;
    template <>
    ApollopredictionLaneSequence from_json<ApollopredictionLaneSequence>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneSequence &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneSequence & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneSequence & dt);
}
