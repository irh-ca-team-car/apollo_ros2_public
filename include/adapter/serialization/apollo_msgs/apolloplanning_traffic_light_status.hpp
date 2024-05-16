#pragma once
#include "apollo_msgs/msg/apolloplanning_traffic_light_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficLightStatus &msg) ;
    ApolloplanningTrafficLightStatus from_json_ApolloplanningTrafficLightStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningTrafficLightStatus from_json<ApolloplanningTrafficLightStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficLightStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficLightStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficLightStatus & dt);
}
