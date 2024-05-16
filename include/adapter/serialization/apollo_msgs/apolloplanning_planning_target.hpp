#pragma once
#include "apollo_msgs/msg/apolloplanning_planning_target.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_stop_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningTarget &msg) ;
    ApolloplanningPlanningTarget from_json_ApolloplanningPlanningTarget (nlohmann::json obj) ;
    template <>
    ApolloplanningPlanningTarget from_json<ApolloplanningPlanningTarget>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningTarget &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningTarget & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningTarget & dt);
}
