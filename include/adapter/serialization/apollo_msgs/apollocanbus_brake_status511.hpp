#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_status511.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeStatus511 &msg) ;
    ApollocanbusBrakeStatus511 from_json_ApollocanbusBrakeStatus511 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeStatus511 from_json<ApollocanbusBrakeStatus511>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeStatus511 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeStatus511 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeStatus511 & dt);
}
