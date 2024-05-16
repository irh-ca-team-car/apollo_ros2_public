#pragma once
#include "apollo_msgs/msg/apolloperception_trajectory.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionTrajectory &msg) ;
    ApolloperceptionTrajectory from_json_ApolloperceptionTrajectory (nlohmann::json obj) ;
    template <>
    ApolloperceptionTrajectory from_json<ApolloperceptionTrajectory>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionTrajectory &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionTrajectory & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionTrajectory & dt);
}
