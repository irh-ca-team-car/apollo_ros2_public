#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_command111.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeCommand111 &msg) ;
    ApollocanbusBrakeCommand111 from_json_ApollocanbusBrakeCommand111 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeCommand111 from_json<ApollocanbusBrakeCommand111>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeCommand111 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeCommand111 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeCommand111 & dt);
}
