#pragma once
#include "apollo_msgs/msg/apolloaudio_audio_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloaudio_topic_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloaudioAudioConf &msg) ;
    ApolloaudioAudioConf from_json_ApolloaudioAudioConf (nlohmann::json obj) ;
    template <>
    ApolloaudioAudioConf from_json<ApolloaudioAudioConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloaudioAudioConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloaudioAudioConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloaudioAudioConf & dt);
}
