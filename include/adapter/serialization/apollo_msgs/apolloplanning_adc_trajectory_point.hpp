#pragma once
#include "apollo_msgs/msg/apolloplanning_adc_trajectory_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_planning_tag.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_common_trajectory_point_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningADCTrajectoryPoint &msg) ;
    ApolloplanningADCTrajectoryPoint from_json_ApolloplanningADCTrajectoryPoint (nlohmann::json obj) ;
    template <>
    ApolloplanningADCTrajectoryPoint from_json<ApolloplanningADCTrajectoryPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningADCTrajectoryPoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningADCTrajectoryPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningADCTrajectoryPoint & dt);
}
