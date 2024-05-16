#pragma once
#include "apollo_msgs/msg/apollodriversvideoconfig_camera_h265_config_compress_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvideoconfigCameraH265ConfigCompressConfig &msg) ;
    ApollodriversvideoconfigCameraH265ConfigCompressConfig from_json_ApollodriversvideoconfigCameraH265ConfigCompressConfig (nlohmann::json obj) ;
    template <>
    ApollodriversvideoconfigCameraH265ConfigCompressConfig from_json<ApollodriversvideoconfigCameraH265ConfigCompressConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvideoconfigCameraH265ConfigCompressConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversvideoconfigCameraH265ConfigCompressConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvideoconfigCameraH265ConfigCompressConfig & dt);
}
