#pragma once
#include "apollo_msgs/msg/apolloplanning_rtk_planning_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRtkPlanningConfig &msg) ;
    ApolloplanningRtkPlanningConfig from_json_ApolloplanningRtkPlanningConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningRtkPlanningConfig from_json<ApolloplanningRtkPlanningConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRtkPlanningConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRtkPlanningConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRtkPlanningConfig & dt);
}
