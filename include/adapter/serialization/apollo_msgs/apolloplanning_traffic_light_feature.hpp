#pragma once
#include "apollo_msgs/msg/apolloplanning_traffic_light_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficLightFeature &msg) ;
    ApolloplanningTrafficLightFeature from_json_ApolloplanningTrafficLightFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningTrafficLightFeature from_json<ApolloplanningTrafficLightFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficLightFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficLightFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficLightFeature & dt);
}
