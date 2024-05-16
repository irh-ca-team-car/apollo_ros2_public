#pragma once
#include "apollo_msgs/msg/apollocanbus_veh_dynamics_rpt413.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehDynamicsRpt413 &msg) ;
    ApollocanbusVehDynamicsRpt413 from_json_ApollocanbusVehDynamicsRpt413 (nlohmann::json obj) ;
    template <>
    ApollocanbusVehDynamicsRpt413 from_json<ApollocanbusVehDynamicsRpt413>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehDynamicsRpt413 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehDynamicsRpt413 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehDynamicsRpt413 & dt);
}
