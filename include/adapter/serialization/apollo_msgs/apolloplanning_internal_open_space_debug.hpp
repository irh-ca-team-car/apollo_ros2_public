#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_open_space_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_trajectories.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_motion.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_obstacle_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalOpenSpaceDebug &msg) ;
    ApolloplanningInternalOpenSpaceDebug from_json_ApolloplanningInternalOpenSpaceDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalOpenSpaceDebug from_json<ApolloplanningInternalOpenSpaceDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalOpenSpaceDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalOpenSpaceDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalOpenSpaceDebug & dt);
}
