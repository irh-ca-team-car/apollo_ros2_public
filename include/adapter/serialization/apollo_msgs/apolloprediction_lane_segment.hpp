#pragma once
#include "apollo_msgs/msg/apolloprediction_lane_segment.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneSegment &msg) ;
    ApollopredictionLaneSegment from_json_ApollopredictionLaneSegment (nlohmann::json obj) ;
    template <>
    ApollopredictionLaneSegment from_json<ApollopredictionLaneSegment>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneSegment &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneSegment & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneSegment & dt);
}
