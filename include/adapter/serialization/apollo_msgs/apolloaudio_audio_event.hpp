#pragma once
#include "apollo_msgs/msg/apolloaudio_audio_event.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_pose.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloaudioAudioEvent &msg) ;
    ApolloaudioAudioEvent from_json_ApolloaudioAudioEvent (nlohmann::json obj) ;
    template <>
    ApolloaudioAudioEvent from_json<ApolloaudioAudioEvent>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloaudioAudioEvent &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloaudioAudioEvent & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloaudioAudioEvent & dt);
}
