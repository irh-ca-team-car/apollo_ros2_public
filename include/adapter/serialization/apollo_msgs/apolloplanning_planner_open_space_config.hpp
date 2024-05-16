#pragma once
#include "apollo_msgs/msg/apolloplanning_planner_open_space_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_roi_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_warm_start_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_dual_variable_warm_start_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_distance_approach_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_iterative_anchoring_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_trajectory_partition_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlannerOpenSpaceConfig &msg) ;
    ApolloplanningPlannerOpenSpaceConfig from_json_ApolloplanningPlannerOpenSpaceConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPlannerOpenSpaceConfig from_json<ApolloplanningPlannerOpenSpaceConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlannerOpenSpaceConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlannerOpenSpaceConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlannerOpenSpaceConfig & dt);
}
