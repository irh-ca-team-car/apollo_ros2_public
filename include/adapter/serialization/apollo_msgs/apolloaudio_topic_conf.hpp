#pragma once
#include "apollo_msgs/msg/apolloaudio_topic_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloaudioTopicConf &msg) ;
    ApolloaudioTopicConf from_json_ApolloaudioTopicConf (nlohmann::json obj) ;
    template <>
    ApolloaudioTopicConf from_json<ApolloaudioTopicConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloaudioTopicConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloaudioTopicConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloaudioTopicConf & dt);
}
