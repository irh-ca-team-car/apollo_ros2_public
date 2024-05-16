#pragma once
#include "apollo_msgs/msg/apolloplanning_bare_intersection_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningBareIntersectionStatus &msg) ;
    ApolloplanningBareIntersectionStatus from_json_ApolloplanningBareIntersectionStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningBareIntersectionStatus from_json<ApolloplanningBareIntersectionStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningBareIntersectionStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningBareIntersectionStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningBareIntersectionStatus & dt);
}
