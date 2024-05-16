#pragma once
#include "apollo_msgs/msg/apolloprediction_trajectory.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionTrajectory &msg) ;
    ApollopredictionTrajectory from_json_ApollopredictionTrajectory (nlohmann::json obj) ;
    template <>
    ApollopredictionTrajectory from_json<ApollopredictionTrajectory>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionTrajectory &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionTrajectory & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionTrajectory & dt);
}
