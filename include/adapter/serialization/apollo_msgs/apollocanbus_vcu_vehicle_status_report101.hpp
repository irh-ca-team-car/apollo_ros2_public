#pragma once
#include "apollo_msgs/msg/apollocanbus_vcu_vehicle_status_report101.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuVehicleStatusReport101 &msg) ;
    ApollocanbusVcuVehicleStatusReport101 from_json_ApollocanbusVcuVehicleStatusReport101 (nlohmann::json obj) ;
    template <>
    ApollocanbusVcuVehicleStatusReport101 from_json<ApollocanbusVcuVehicleStatusReport101>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuVehicleStatusReport101 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuVehicleStatusReport101 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuVehicleStatusReport101 & dt);
}
