#pragma once
#include "apollo_msgs/msg/apolloplanning_traffic_light_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficLightConfig &msg) ;
    ApolloplanningTrafficLightConfig from_json_ApolloplanningTrafficLightConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningTrafficLightConfig from_json<ApolloplanningTrafficLightConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficLightConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficLightConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficLightConfig & dt);
}
