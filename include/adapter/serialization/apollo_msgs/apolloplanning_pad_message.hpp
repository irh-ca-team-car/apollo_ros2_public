#pragma once
#include "apollo_msgs/msg/apolloplanning_pad_message.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPadMessage &msg) ;
    ApolloplanningPadMessage from_json_ApolloplanningPadMessage (nlohmann::json obj) ;
    template <>
    ApolloplanningPadMessage from_json<ApolloplanningPadMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPadMessage &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPadMessage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPadMessage & dt);
}
