#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_emergency_stop_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioEmergencyStopConfig &msg) ;
    ApolloplanningScenarioEmergencyStopConfig from_json_ApolloplanningScenarioEmergencyStopConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioEmergencyStopConfig from_json<ApolloplanningScenarioEmergencyStopConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioEmergencyStopConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioEmergencyStopConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioEmergencyStopConfig & dt);
}
