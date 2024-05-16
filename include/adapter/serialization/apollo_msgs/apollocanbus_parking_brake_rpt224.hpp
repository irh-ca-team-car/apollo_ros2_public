#pragma once
#include "apollo_msgs/msg/apollocanbus_parking_brake_rpt224.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkingBrakeRpt224 &msg) ;
    ApollocanbusParkingBrakeRpt224 from_json_ApollocanbusParkingBrakeRpt224 (nlohmann::json obj) ;
    template <>
    ApollocanbusParkingBrakeRpt224 from_json<ApollocanbusParkingBrakeRpt224>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkingBrakeRpt224 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkingBrakeRpt224 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkingBrakeRpt224 & dt);
}
