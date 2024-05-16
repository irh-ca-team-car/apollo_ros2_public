#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_camera_calibrator.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraCameraCalibrator &msg) ;
    ApolloperceptioncameraCameraCalibrator from_json_ApolloperceptioncameraCameraCalibrator (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraCameraCalibrator from_json<ApolloperceptioncameraCameraCalibrator>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraCameraCalibrator &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraCameraCalibrator & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraCameraCalibrator & dt);
}
