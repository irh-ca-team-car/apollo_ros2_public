#pragma once
#include "apollo_msgs/msg/apollodrivers_smartereye_obstaclesoutput_obstacles.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodrivers_output_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversSmartereyeObstaclesoutputObstacles &msg) ;
    ApollodriversSmartereyeObstaclesoutputObstacles from_json_ApollodriversSmartereyeObstaclesoutputObstacles (nlohmann::json obj) ;
    template <>
    ApollodriversSmartereyeObstaclesoutputObstacles from_json<ApollodriversSmartereyeObstaclesoutputObstacles>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversSmartereyeObstaclesoutputObstacles &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversSmartereyeObstaclesoutputObstacles & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversSmartereyeObstaclesoutputObstacles & dt);
}
