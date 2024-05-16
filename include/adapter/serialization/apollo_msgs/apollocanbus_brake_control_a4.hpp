#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_control_a4.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeControlA4 &msg) ;
    ApollocanbusBrakeControlA4 from_json_ApollocanbusBrakeControlA4 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeControlA4 from_json<ApollocanbusBrakeControlA4>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeControlA4 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeControlA4 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeControlA4 & dt);
}
