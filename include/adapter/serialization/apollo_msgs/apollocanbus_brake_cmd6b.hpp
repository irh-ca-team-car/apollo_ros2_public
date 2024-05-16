#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_cmd6b.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeCmd6b &msg) ;
    ApollocanbusBrakeCmd6b from_json_ApollocanbusBrakeCmd6b (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeCmd6b from_json<ApollocanbusBrakeCmd6b>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeCmd6b &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeCmd6b & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeCmd6b & dt);
}
