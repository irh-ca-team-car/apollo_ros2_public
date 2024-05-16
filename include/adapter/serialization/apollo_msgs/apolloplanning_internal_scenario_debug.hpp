#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_scenario_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalScenarioDebug &msg) ;
    ApolloplanningInternalScenarioDebug from_json_ApolloplanningInternalScenarioDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalScenarioDebug from_json<ApolloplanningInternalScenarioDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalScenarioDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalScenarioDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalScenarioDebug & dt);
}
