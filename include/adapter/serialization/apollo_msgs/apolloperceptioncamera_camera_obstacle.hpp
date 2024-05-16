#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_camera_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_perception_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraCameraObstacle &msg) ;
    ApolloperceptioncameraCameraObstacle from_json_ApolloperceptioncameraCameraObstacle (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraCameraObstacle from_json<ApolloperceptioncameraCameraObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraCameraObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraCameraObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraCameraObstacle & dt);
}
