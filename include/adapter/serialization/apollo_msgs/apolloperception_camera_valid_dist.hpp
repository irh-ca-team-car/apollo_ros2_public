#pragma once
#include "apollo_msgs/msg/apolloperception_camera_valid_dist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionCameraValidDist &msg) ;
    ApolloperceptionCameraValidDist from_json_ApolloperceptionCameraValidDist (nlohmann::json obj) ;
    template <>
    ApolloperceptionCameraValidDist from_json<ApolloperceptionCameraValidDist>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionCameraValidDist &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionCameraValidDist & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionCameraValidDist & dt);
}
