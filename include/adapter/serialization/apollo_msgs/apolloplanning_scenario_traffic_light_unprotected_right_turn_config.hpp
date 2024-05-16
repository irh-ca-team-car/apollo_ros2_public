#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_traffic_light_unprotected_right_turn_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig &msg) ;
    ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig from_json_ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig from_json<ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig & dt);
}
