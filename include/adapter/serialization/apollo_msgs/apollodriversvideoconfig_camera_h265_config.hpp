#pragma once
#include "apollo_msgs/msg/apollodriversvideoconfig_camera_h265_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvideoconfigCameraH265Config &msg) ;
    ApollodriversvideoconfigCameraH265Config from_json_ApollodriversvideoconfigCameraH265Config (nlohmann::json obj) ;
    template <>
    ApollodriversvideoconfigCameraH265Config from_json<ApollodriversvideoconfigCameraH265Config>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvideoconfigCameraH265Config &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversvideoconfigCameraH265Config & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvideoconfigCameraH265Config & dt);
}
