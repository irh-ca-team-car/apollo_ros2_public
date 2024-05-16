#pragma once
#include "apollo_msgs/msg/apolloplanning_standard_planning_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStandardPlanningConfig &msg) ;
    ApolloplanningStandardPlanningConfig from_json_ApolloplanningStandardPlanningConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningStandardPlanningConfig from_json<ApolloplanningStandardPlanningConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStandardPlanningConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStandardPlanningConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStandardPlanningConfig & dt);
}
