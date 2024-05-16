#pragma once
#include "apollo_msgs/msg/apollocontrol_pad_message.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolPadMessage &msg) ;
    ApollocontrolPadMessage from_json_ApollocontrolPadMessage (nlohmann::json obj) ;
    template <>
    ApollocontrolPadMessage from_json<ApollocontrolPadMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolPadMessage &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolPadMessage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolPadMessage & dt);
}
