#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_trajectories.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalTrajectories &msg) ;
    ApolloplanningInternalTrajectories from_json_ApolloplanningInternalTrajectories (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalTrajectories from_json<ApolloplanningInternalTrajectories>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalTrajectories &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalTrajectories & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalTrajectories & dt);
}
