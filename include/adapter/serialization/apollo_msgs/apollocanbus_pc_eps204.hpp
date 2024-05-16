#pragma once
#include "apollo_msgs/msg/apollocanbus_pc_eps204.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcEps204 &msg) ;
    ApollocanbusPcEps204 from_json_ApollocanbusPcEps204 (nlohmann::json obj) ;
    template <>
    ApollocanbusPcEps204 from_json<ApollocanbusPcEps204>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcEps204 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcEps204 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcEps204 & dt);
}
