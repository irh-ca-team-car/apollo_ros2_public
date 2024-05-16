#pragma once
#include "apollo_msgs/msg/gps_pose.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const GPSPose &msg) ;
    GPSPose from_json_GPSPose (nlohmann::json obj) ;
    template <>
    GPSPose from_json<GPSPose>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, GPSPose &dt);
    std::ostream & operator<<(std::ostream & os, const GPSPose & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const GPSPose & dt);
}
