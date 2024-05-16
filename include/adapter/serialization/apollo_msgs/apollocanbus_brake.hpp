#pragma once
#include "apollo_msgs/msg/apollocanbus_brake.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrake &msg) ;
    ApollocanbusBrake from_json_ApollocanbusBrake (nlohmann::json obj) ;
    template <>
    ApollocanbusBrake from_json<ApollocanbusBrake>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrake &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrake & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrake & dt);
}
