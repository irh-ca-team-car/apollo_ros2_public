#pragma once
#include "apollo_msgs/msg/apolloprediction_lane_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLanePoint &msg) ;
    ApollopredictionLanePoint from_json_ApollopredictionLanePoint (nlohmann::json obj) ;
    template <>
    ApollopredictionLanePoint from_json<ApollopredictionLanePoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLanePoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLanePoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLanePoint & dt);
}
