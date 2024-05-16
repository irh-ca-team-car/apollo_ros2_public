#pragma once
#include "apollo_msgs/msg/apollodriversmicrophoneconfig_microphone_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversmicrophoneconfigMicrophoneConfig &msg) ;
    ApollodriversmicrophoneconfigMicrophoneConfig from_json_ApollodriversmicrophoneconfigMicrophoneConfig (nlohmann::json obj) ;
    template <>
    ApollodriversmicrophoneconfigMicrophoneConfig from_json<ApollodriversmicrophoneconfigMicrophoneConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversmicrophoneconfigMicrophoneConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversmicrophoneconfigMicrophoneConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversmicrophoneconfigMicrophoneConfig & dt);
}
