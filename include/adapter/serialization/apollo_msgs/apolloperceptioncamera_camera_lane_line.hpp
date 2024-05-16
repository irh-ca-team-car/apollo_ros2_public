#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_camera_lane_line.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_lane_line_cubic_curve.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point2_d.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_end_points.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraCameraLaneLine &msg) ;
    ApolloperceptioncameraCameraLaneLine from_json_ApolloperceptioncameraCameraLaneLine (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraCameraLaneLine from_json<ApolloperceptioncameraCameraLaneLine>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraCameraLaneLine &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraCameraLaneLine & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraCameraLaneLine & dt);
}
