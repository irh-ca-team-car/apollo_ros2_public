#pragma once
#include "apollo_msgs/msg/apolloplanning_open_space_trajectory_provider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_trajectory_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceTrajectoryProviderConfig &msg) ;
    ApolloplanningOpenSpaceTrajectoryProviderConfig from_json_ApolloplanningOpenSpaceTrajectoryProviderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningOpenSpaceTrajectoryProviderConfig from_json<ApolloplanningOpenSpaceTrajectoryProviderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceTrajectoryProviderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceTrajectoryProviderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceTrajectoryProviderConfig & dt);
}
