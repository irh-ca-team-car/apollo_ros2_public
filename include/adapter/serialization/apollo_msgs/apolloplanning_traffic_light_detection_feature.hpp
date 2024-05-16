#pragma once
#include "apollo_msgs/msg/apolloplanning_traffic_light_detection_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficLightDetectionFeature &msg) ;
    ApolloplanningTrafficLightDetectionFeature from_json_ApolloplanningTrafficLightDetectionFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningTrafficLightDetectionFeature from_json<ApolloplanningTrafficLightDetectionFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficLightDetectionFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficLightDetectionFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficLightDetectionFeature & dt);
}
