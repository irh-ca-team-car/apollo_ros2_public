#pragma once
#include "apollo_msgs/msg/apollocommon_trajectory_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_path_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_gaussian_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonTrajectoryPoint &msg) ;
    ApollocommonTrajectoryPoint from_json_ApollocommonTrajectoryPoint (nlohmann::json obj) ;
    template <>
    ApollocommonTrajectoryPoint from_json<ApollocommonTrajectoryPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonTrajectoryPoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonTrajectoryPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonTrajectoryPoint & dt);
}
