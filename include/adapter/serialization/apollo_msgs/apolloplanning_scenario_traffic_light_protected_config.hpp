#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_traffic_light_protected_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioTrafficLightProtectedConfig &msg) ;
    ApolloplanningScenarioTrafficLightProtectedConfig from_json_ApolloplanningScenarioTrafficLightProtectedConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioTrafficLightProtectedConfig from_json<ApolloplanningScenarioTrafficLightProtectedConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioTrafficLightProtectedConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioTrafficLightProtectedConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioTrafficLightProtectedConfig & dt);
}
