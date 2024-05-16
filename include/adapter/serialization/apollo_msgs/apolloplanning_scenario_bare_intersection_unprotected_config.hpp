#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_bare_intersection_unprotected_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioBareIntersectionUnprotectedConfig &msg) ;
    ApolloplanningScenarioBareIntersectionUnprotectedConfig from_json_ApolloplanningScenarioBareIntersectionUnprotectedConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioBareIntersectionUnprotectedConfig from_json<ApolloplanningScenarioBareIntersectionUnprotectedConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioBareIntersectionUnprotectedConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioBareIntersectionUnprotectedConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioBareIntersectionUnprotectedConfig & dt);
}
