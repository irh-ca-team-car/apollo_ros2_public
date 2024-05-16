#pragma once
#include "apollo_msgs/msg/apolloprediction_lane.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_graph.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLane &msg) ;
    ApollopredictionLane from_json_ApollopredictionLane (nlohmann::json obj) ;
    template <>
    ApollopredictionLane from_json<ApollopredictionLane>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLane &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLane & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLane & dt);
}
