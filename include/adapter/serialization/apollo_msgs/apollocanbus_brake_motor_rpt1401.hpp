#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_motor_rpt1401.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeMotorRpt1401 &msg) ;
    ApollocanbusBrakeMotorRpt1401 from_json_ApollocanbusBrakeMotorRpt1401 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeMotorRpt1401 from_json<ApollocanbusBrakeMotorRpt1401>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeMotorRpt1401 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeMotorRpt1401 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeMotorRpt1401 & dt);
}
