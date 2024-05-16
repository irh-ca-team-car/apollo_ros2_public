#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_stop_sign_unprotected_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioStopSignUnprotectedConfig &msg) ;
    ApolloplanningScenarioStopSignUnprotectedConfig from_json_ApolloplanningScenarioStopSignUnprotectedConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioStopSignUnprotectedConfig from_json<ApolloplanningScenarioStopSignUnprotectedConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioStopSignUnprotectedConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioStopSignUnprotectedConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioStopSignUnprotectedConfig & dt);
}
