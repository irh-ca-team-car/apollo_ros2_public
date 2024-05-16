#pragma once
#include "apollo_msgs/msg/apollocanbus_park_command104.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkCommand104 &msg) ;
    ApollocanbusParkCommand104 from_json_ApollocanbusParkCommand104 (nlohmann::json obj) ;
    template <>
    ApollocanbusParkCommand104 from_json<ApollocanbusParkCommand104>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkCommand104 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkCommand104 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkCommand104 & dt);
}
