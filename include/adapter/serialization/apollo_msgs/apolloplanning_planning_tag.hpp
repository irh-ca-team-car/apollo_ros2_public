#pragma once
#include "apollo_msgs/msg/apolloplanning_planning_tag.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_overlap_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningTag &msg) ;
    ApolloplanningPlanningTag from_json_ApolloplanningPlanningTag (nlohmann::json obj) ;
    template <>
    ApolloplanningPlanningTag from_json<ApolloplanningPlanningTag>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningTag &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningTag & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningTag & dt);
}
