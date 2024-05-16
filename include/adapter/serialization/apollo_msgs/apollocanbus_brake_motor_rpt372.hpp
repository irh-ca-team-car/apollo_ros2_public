#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_motor_rpt372.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeMotorRpt372 &msg) ;
    ApollocanbusBrakeMotorRpt372 from_json_ApollocanbusBrakeMotorRpt372 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeMotorRpt372 from_json<ApollocanbusBrakeMotorRpt372>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeMotorRpt372 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeMotorRpt372 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeMotorRpt372 & dt);
}
