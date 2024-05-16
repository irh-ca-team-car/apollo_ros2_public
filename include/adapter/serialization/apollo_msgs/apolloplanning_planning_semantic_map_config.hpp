#pragma once
#include "apollo_msgs/msg/apolloplanning_planning_semantic_map_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningSemanticMapConfig &msg) ;
    ApolloplanningPlanningSemanticMapConfig from_json_ApolloplanningPlanningSemanticMapConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPlanningSemanticMapConfig from_json<ApolloplanningPlanningSemanticMapConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningSemanticMapConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningSemanticMapConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningSemanticMapConfig & dt);
}
