#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_configscenario_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_stage_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioConfig &msg) ;
    ApolloplanningScenarioConfig from_json_ApolloplanningScenarioConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioConfig from_json<ApolloplanningScenarioConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioConfig & dt);
}
