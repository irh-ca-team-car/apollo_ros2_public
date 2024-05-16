#pragma once
#include "apollo_msgs/msg/apollodriversmicrophoneconfig_audio_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversmicrophoneconfig_microphone_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversmicrophoneconfig_channel_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversmicrophoneconfigAudioData &msg) ;
    ApollodriversmicrophoneconfigAudioData from_json_ApollodriversmicrophoneconfigAudioData (nlohmann::json obj) ;
    template <>
    ApollodriversmicrophoneconfigAudioData from_json<ApollodriversmicrophoneconfigAudioData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversmicrophoneconfigAudioData &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversmicrophoneconfigAudioData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversmicrophoneconfigAudioData & dt);
}
