#pragma once
#include "apollo_msgs/msg/apolloplanning_planning_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_topic_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planning_configplanning_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_task_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningConfig &msg) ;
    ApolloplanningPlanningConfig from_json_ApolloplanningPlanningConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPlanningConfig from_json<ApolloplanningPlanningConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningConfig & dt);
}
