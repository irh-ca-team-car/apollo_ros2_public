#pragma once
#include "apollo_msgs/msg/apolloprediction_junction_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_junction_exit.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionJunctionFeature &msg) ;
    ApollopredictionJunctionFeature from_json_ApollopredictionJunctionFeature (nlohmann::json obj) ;
    template <>
    ApollopredictionJunctionFeature from_json<ApollopredictionJunctionFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionJunctionFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionJunctionFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionJunctionFeature & dt);
}
