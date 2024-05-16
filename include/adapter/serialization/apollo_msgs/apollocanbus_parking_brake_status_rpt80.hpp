#pragma once
#include "apollo_msgs/msg/apollocanbus_parking_brake_status_rpt80.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkingBrakeStatusRpt80 &msg) ;
    ApollocanbusParkingBrakeStatusRpt80 from_json_ApollocanbusParkingBrakeStatusRpt80 (nlohmann::json obj) ;
    template <>
    ApollocanbusParkingBrakeStatusRpt80 from_json<ApollocanbusParkingBrakeStatusRpt80>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkingBrakeStatusRpt80 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkingBrakeStatusRpt80 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkingBrakeStatusRpt80 & dt);
}
