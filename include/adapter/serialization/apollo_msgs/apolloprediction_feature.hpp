#pragma once
#include "apollo_msgs/msg/apolloprediction_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_junction_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_priority.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_trajectory.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionFeature &msg) ;
    ApollopredictionFeature from_json_ApollopredictionFeature (nlohmann::json obj) ;
    template <>
    ApollopredictionFeature from_json<ApollopredictionFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionFeature & dt);
}
