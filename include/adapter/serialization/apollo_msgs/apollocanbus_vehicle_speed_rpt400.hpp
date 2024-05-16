#pragma once
#include "apollo_msgs/msg/apollocanbus_vehicle_speed_rpt400.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleSpeedRpt400 &msg) ;
    ApollocanbusVehicleSpeedRpt400 from_json_ApollocanbusVehicleSpeedRpt400 (nlohmann::json obj) ;
    template <>
    ApollocanbusVehicleSpeedRpt400 from_json<ApollocanbusVehicleSpeedRpt400>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleSpeedRpt400 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleSpeedRpt400 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleSpeedRpt400 & dt);
}
