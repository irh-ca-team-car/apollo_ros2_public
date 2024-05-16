#pragma once
#include "apollo_msgs/msg/camera_image.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/vector3.hpp"
#include "adapter/serialization/apollo_msgs/quaternion.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const CameraImage &msg) ;
    CameraImage from_json_CameraImage (nlohmann::json obj) ;
    template <>
    CameraImage from_json<CameraImage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, CameraImage &dt);
    std::ostream & operator<<(std::ostream & os, const CameraImage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const CameraImage & dt);
}
