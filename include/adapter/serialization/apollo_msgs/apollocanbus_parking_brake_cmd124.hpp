#pragma once
#include "apollo_msgs/msg/apollocanbus_parking_brake_cmd124.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkingBrakeCmd124 &msg) ;
    ApollocanbusParkingBrakeCmd124 from_json_ApollocanbusParkingBrakeCmd124 (nlohmann::json obj) ;
    template <>
    ApollocanbusParkingBrakeCmd124 from_json<ApollocanbusParkingBrakeCmd124>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkingBrakeCmd124 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkingBrakeCmd124 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkingBrakeCmd124 & dt);
}
