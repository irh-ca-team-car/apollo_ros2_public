#pragma once
#include "apollo_msgs/msg/apollocommonutiltest_simple_repeated_message.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommonutiltest_simple_message.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonutiltestSimpleRepeatedMessage &msg) ;
    ApollocommonutiltestSimpleRepeatedMessage from_json_ApollocommonutiltestSimpleRepeatedMessage (nlohmann::json obj) ;
    template <>
    ApollocommonutiltestSimpleRepeatedMessage from_json<ApollocommonutiltestSimpleRepeatedMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonutiltestSimpleRepeatedMessage &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonutiltestSimpleRepeatedMessage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonutiltestSimpleRepeatedMessage & dt);
}
