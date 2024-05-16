#pragma once
#include "apollo_msgs/msg/apolloplanning_topic_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTopicConfig &msg) ;
    ApolloplanningTopicConfig from_json_ApolloplanningTopicConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningTopicConfig from_json<ApolloplanningTopicConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTopicConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTopicConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTopicConfig & dt);
}
