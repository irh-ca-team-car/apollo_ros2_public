#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_camera_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_calibrator.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_lane_line.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraCameraDebug &msg) ;
    ApolloperceptioncameraCameraDebug from_json_ApolloperceptioncameraCameraDebug (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraCameraDebug from_json<ApolloperceptioncameraCameraDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraCameraDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraCameraDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraCameraDebug & dt);
}
