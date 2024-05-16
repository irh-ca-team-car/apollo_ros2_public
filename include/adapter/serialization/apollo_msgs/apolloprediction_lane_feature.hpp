#pragma once
#include "apollo_msgs/msg/apolloprediction_lane_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneFeature &msg) ;
    ApollopredictionLaneFeature from_json_ApollopredictionLaneFeature (nlohmann::json obj) ;
    template <>
    ApollopredictionLaneFeature from_json<ApollopredictionLaneFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneFeature & dt);
}
