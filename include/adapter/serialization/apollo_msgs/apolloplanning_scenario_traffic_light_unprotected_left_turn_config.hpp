#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_traffic_light_unprotected_left_turn_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig &msg) ;
    ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig from_json_ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig from_json<ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig & dt);
}
