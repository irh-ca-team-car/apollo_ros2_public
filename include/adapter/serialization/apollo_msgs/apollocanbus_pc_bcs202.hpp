#pragma once
#include "apollo_msgs/msg/apollocanbus_pc_bcs202.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcBcs202 &msg) ;
    ApollocanbusPcBcs202 from_json_ApollocanbusPcBcs202 (nlohmann::json obj) ;
    template <>
    ApollocanbusPcBcs202 from_json<ApollocanbusPcBcs202>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcBcs202 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcBcs202 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcBcs202 & dt);
}
