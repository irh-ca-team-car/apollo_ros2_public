#pragma once
#include "apollo_msgs/msg/apolloperception_perception_obstacles.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_perception_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_lane_markers.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_cipv_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionPerceptionObstacles &msg) ;
    ApolloperceptionPerceptionObstacles from_json_ApolloperceptionPerceptionObstacles (nlohmann::json obj) ;
    template <>
    ApolloperceptionPerceptionObstacles from_json<ApolloperceptionPerceptionObstacles>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionPerceptionObstacles &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionPerceptionObstacles & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionPerceptionObstacles & dt);
}
