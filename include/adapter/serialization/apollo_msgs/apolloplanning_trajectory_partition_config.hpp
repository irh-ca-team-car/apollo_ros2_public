#pragma once
#include "apollo_msgs/msg/apolloplanning_trajectory_partition_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrajectoryPartitionConfig &msg) ;
    ApolloplanningTrajectoryPartitionConfig from_json_ApolloplanningTrajectoryPartitionConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningTrajectoryPartitionConfig from_json<ApolloplanningTrajectoryPartitionConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrajectoryPartitionConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrajectoryPartitionConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrajectoryPartitionConfig & dt);
}
