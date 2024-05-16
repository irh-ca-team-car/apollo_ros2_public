#pragma once
#include "apollo_msgs/msg/apollocommonutiltest_simple_message.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonutiltestSimpleMessage &msg) ;
    ApollocommonutiltestSimpleMessage from_json_ApollocommonutiltestSimpleMessage (nlohmann::json obj) ;
    template <>
    ApollocommonutiltestSimpleMessage from_json<ApollocommonutiltestSimpleMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonutiltestSimpleMessage &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonutiltestSimpleMessage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonutiltestSimpleMessage & dt);
}
