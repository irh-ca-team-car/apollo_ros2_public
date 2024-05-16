#pragma once
#include "apollo_msgs/msg/apollocommon_trajectory.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonTrajectory &msg) ;
    ApollocommonTrajectory from_json_ApollocommonTrajectory (nlohmann::json obj) ;
    template <>
    ApollocommonTrajectory from_json<ApollocommonTrajectory>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonTrajectory &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonTrajectory & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonTrajectory & dt);
}
