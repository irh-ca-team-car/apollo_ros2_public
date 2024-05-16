#pragma once
#include "apollo_msgs/msg/apolloplanning_change_lane_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningChangeLaneStatus &msg) ;
    ApolloplanningChangeLaneStatus from_json_ApolloplanningChangeLaneStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningChangeLaneStatus from_json<ApolloplanningChangeLaneStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningChangeLaneStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningChangeLaneStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningChangeLaneStatus & dt);
}
