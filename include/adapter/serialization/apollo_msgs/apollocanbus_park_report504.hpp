#pragma once
#include "apollo_msgs/msg/apollocanbus_park_report504.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkReport504 &msg) ;
    ApollocanbusParkReport504 from_json_ApollocanbusParkReport504 (nlohmann::json obj) ;
    template <>
    ApollocanbusParkReport504 from_json<ApollocanbusParkReport504>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkReport504 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkReport504 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkReport504 & dt);
}
