#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_park_and_go_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioParkAndGoConfig &msg) ;
    ApolloplanningScenarioParkAndGoConfig from_json_ApolloplanningScenarioParkAndGoConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioParkAndGoConfig from_json<ApolloplanningScenarioParkAndGoConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioParkAndGoConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioParkAndGoConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioParkAndGoConfig & dt);
}
