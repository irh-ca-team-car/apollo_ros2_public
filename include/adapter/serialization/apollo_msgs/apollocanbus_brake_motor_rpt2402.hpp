#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_motor_rpt2402.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeMotorRpt2402 &msg) ;
    ApollocanbusBrakeMotorRpt2402 from_json_ApollocanbusBrakeMotorRpt2402 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeMotorRpt2402 from_json<ApollocanbusBrakeMotorRpt2402>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeMotorRpt2402 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeMotorRpt2402 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeMotorRpt2402 & dt);
}
