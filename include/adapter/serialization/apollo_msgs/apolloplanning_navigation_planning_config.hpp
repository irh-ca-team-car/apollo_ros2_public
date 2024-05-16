#pragma once
#include "apollo_msgs/msg/apolloplanning_navigation_planning_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_planner_navi_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningNavigationPlanningConfig &msg) ;
    ApolloplanningNavigationPlanningConfig from_json_ApolloplanningNavigationPlanningConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningNavigationPlanningConfig from_json<ApolloplanningNavigationPlanningConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningNavigationPlanningConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningNavigationPlanningConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningNavigationPlanningConfig & dt);
}
