#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_motor_rpt271.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeMotorRpt271 &msg) ;
    ApollocanbusBrakeMotorRpt271 from_json_ApollocanbusBrakeMotorRpt271 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeMotorRpt271 from_json<ApollocanbusBrakeMotorRpt271>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeMotorRpt271 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeMotorRpt271 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeMotorRpt271 & dt);
}
