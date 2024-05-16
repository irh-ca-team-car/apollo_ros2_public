#pragma once
#include "apollo_msgs/msg/apollocanbus_torque_control_a3.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTorqueControlA3 &msg) ;
    ApollocanbusTorqueControlA3 from_json_ApollocanbusTorqueControlA3 (nlohmann::json obj) ;
    template <>
    ApollocanbusTorqueControlA3 from_json<ApollocanbusTorqueControlA3>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTorqueControlA3 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTorqueControlA3 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTorqueControlA3 & dt);
}
