#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioStatus &msg) ;
    ApolloplanningScenarioStatus from_json_ApolloplanningScenarioStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioStatus from_json<ApolloplanningScenarioStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioStatus & dt);
}
