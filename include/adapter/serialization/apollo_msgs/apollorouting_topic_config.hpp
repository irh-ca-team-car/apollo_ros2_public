#pragma once
#include "apollo_msgs/msg/apollorouting_topic_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingTopicConfig &msg) ;
    ApolloroutingTopicConfig from_json_ApolloroutingTopicConfig (nlohmann::json obj) ;
    template <>
    ApolloroutingTopicConfig from_json<ApolloroutingTopicConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingTopicConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingTopicConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingTopicConfig & dt);
}
