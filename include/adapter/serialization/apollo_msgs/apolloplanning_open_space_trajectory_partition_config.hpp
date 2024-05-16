#pragma once
#include "apollo_msgs/msg/apolloplanning_open_space_trajectory_partition_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceTrajectoryPartitionConfig &msg) ;
    ApolloplanningOpenSpaceTrajectoryPartitionConfig from_json_ApolloplanningOpenSpaceTrajectoryPartitionConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningOpenSpaceTrajectoryPartitionConfig from_json<ApolloplanningOpenSpaceTrajectoryPartitionConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceTrajectoryPartitionConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceTrajectoryPartitionConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceTrajectoryPartitionConfig & dt);
}
