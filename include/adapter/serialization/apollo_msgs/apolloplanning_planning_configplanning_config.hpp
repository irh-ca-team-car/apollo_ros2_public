#pragma once
#include "apollo_msgs/msg/apolloplanning_planning_configplanning_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_rtk_planning_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_standard_planning_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_navigation_planning_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningConfigplanningConfig &msg) ;
    ApolloplanningPlanningConfigplanningConfig from_json_ApolloplanningPlanningConfigplanningConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPlanningConfigplanningConfig from_json<ApolloplanningPlanningConfigplanningConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningConfigplanningConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningConfigplanningConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningConfigplanningConfig & dt);
}
