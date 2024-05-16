#pragma once
#include "apollo_msgs/msg/apollodrivers_smartereye_obstacles.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_smartereye_obstaclesoutput_obstacles.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversSmartereyeObstacles &msg) ;
    ApollodriversSmartereyeObstacles from_json_ApollodriversSmartereyeObstacles (nlohmann::json obj) ;
    template <>
    ApollodriversSmartereyeObstacles from_json<ApollodriversSmartereyeObstacles>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversSmartereyeObstacles &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversSmartereyeObstacles & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversSmartereyeObstacles & dt);
}
