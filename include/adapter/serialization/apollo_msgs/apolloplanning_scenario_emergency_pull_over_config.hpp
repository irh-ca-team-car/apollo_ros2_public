#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_emergency_pull_over_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioEmergencyPullOverConfig &msg) ;
    ApolloplanningScenarioEmergencyPullOverConfig from_json_ApolloplanningScenarioEmergencyPullOverConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioEmergencyPullOverConfig from_json<ApolloplanningScenarioEmergencyPullOverConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioEmergencyPullOverConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioEmergencyPullOverConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioEmergencyPullOverConfig & dt);
}
