#pragma once
#include "apollo_msgs/msg/apolloplanning_planning_stats.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_stats_group.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningStats &msg) ;
    ApolloplanningPlanningStats from_json_ApolloplanningPlanningStats (nlohmann::json obj) ;
    template <>
    ApolloplanningPlanningStats from_json<ApolloplanningPlanningStats>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningStats &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningStats & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningStats & dt);
}
