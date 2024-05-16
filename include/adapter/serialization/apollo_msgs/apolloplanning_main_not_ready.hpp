#pragma once
#include "apollo_msgs/msg/apolloplanning_main_not_ready.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainNotReady &msg) ;
    ApolloplanningMainNotReady from_json_ApolloplanningMainNotReady (nlohmann::json obj) ;
    template <>
    ApolloplanningMainNotReady from_json<ApolloplanningMainNotReady>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainNotReady &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainNotReady & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainNotReady & dt);
}
