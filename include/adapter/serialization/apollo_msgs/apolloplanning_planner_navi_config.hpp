#pragma once
#include "apollo_msgs/msg/apolloplanning_planner_navi_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_navi_path_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_navi_speed_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_navi_obstacle_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlannerNaviConfig &msg) ;
    ApolloplanningPlannerNaviConfig from_json_ApolloplanningPlannerNaviConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPlannerNaviConfig from_json<ApolloplanningPlannerNaviConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlannerNaviConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlannerNaviConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlannerNaviConfig & dt);
}
