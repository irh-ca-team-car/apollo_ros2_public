#pragma once
#include "apollo_msgs/msg/apolloaudio_audio_detection.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloaudioAudioDetection &msg) ;
    ApolloaudioAudioDetection from_json_ApolloaudioAudioDetection (nlohmann::json obj) ;
    template <>
    ApolloaudioAudioDetection from_json<ApolloaudioAudioDetection>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloaudioAudioDetection &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloaudioAudioDetection & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloaudioAudioDetection & dt);
}
