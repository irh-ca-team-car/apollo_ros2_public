#pragma once
#include "apollo_msgs/msg/frame.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/vector3.hpp"
#include "adapter/serialization/apollo_msgs/quaternion.hpp"
#include "adapter/serialization/apollo_msgs/gps_pose.hpp"
#include "adapter/serialization/apollo_msgs/vector4.hpp"
#include "adapter/serialization/apollo_msgs/radar_point.hpp"
#include "adapter/serialization/apollo_msgs/camera_image.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Frame &msg) ;
    Frame from_json_Frame (nlohmann::json obj) ;
    template <>
    Frame from_json<Frame>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Frame &dt);
    std::ostream & operator<<(std::ostream & os, const Frame & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Frame & dt);
}
