#pragma once
#include "apollo_msgs/msg/apollocanbus_parking_control_a5.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkingControlA5 &msg) ;
    ApollocanbusParkingControlA5 from_json_ApollocanbusParkingControlA5 (nlohmann::json obj) ;
    template <>
    ApollocanbusParkingControlA5 from_json<ApollocanbusParkingControlA5>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkingControlA5 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkingControlA5 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkingControlA5 & dt);
}
