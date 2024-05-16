#pragma once
#include "apollo_msgs/msg/apolloprediction_topic_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionTopicConf &msg) ;
    ApollopredictionTopicConf from_json_ApollopredictionTopicConf (nlohmann::json obj) ;
    template <>
    ApollopredictionTopicConf from_json<ApollopredictionTopicConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionTopicConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionTopicConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionTopicConf & dt);
}
