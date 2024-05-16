#pragma once
#include "apollo_msgs/msg/apolloprediction_lane_graph.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_sequence.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneGraph &msg) ;
    ApollopredictionLaneGraph from_json_ApollopredictionLaneGraph (nlohmann::json obj) ;
    template <>
    ApollopredictionLaneGraph from_json<ApollopredictionLaneGraph>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneGraph &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneGraph & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneGraph & dt);
}
