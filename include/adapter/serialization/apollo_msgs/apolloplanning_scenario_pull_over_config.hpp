#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_pull_over_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioPullOverConfig &msg) ;
    ApolloplanningScenarioPullOverConfig from_json_ApolloplanningScenarioPullOverConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioPullOverConfig from_json<ApolloplanningScenarioPullOverConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioPullOverConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioPullOverConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioPullOverConfig & dt);
}
