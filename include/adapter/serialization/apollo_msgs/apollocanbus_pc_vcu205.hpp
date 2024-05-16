#pragma once
#include "apollo_msgs/msg/apollocanbus_pc_vcu205.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcVcu205 &msg) ;
    ApollocanbusPcVcu205 from_json_ApollocanbusPcVcu205 (nlohmann::json obj) ;
    template <>
    ApollocanbusPcVcu205 from_json<ApollocanbusPcVcu205>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcVcu205 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcVcu205 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcVcu205 & dt);
}
