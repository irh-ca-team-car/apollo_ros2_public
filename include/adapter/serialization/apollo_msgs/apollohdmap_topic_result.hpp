#pragma once
#include "apollo_msgs/msg/apollohdmap_topic_result.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapTopicResult &msg) ;
    ApollohdmapTopicResult from_json_ApollohdmapTopicResult (nlohmann::json obj) ;
    template <>
    ApollohdmapTopicResult from_json<ApollohdmapTopicResult>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapTopicResult &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapTopicResult & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapTopicResult & dt);
}
