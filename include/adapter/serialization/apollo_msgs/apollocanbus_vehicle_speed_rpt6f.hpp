#pragma once
#include "apollo_msgs/msg/apollocanbus_vehicle_speed_rpt6f.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleSpeedRpt6f &msg) ;
    ApollocanbusVehicleSpeedRpt6f from_json_ApollocanbusVehicleSpeedRpt6f (nlohmann::json obj) ;
    template <>
    ApollocanbusVehicleSpeedRpt6f from_json<ApollocanbusVehicleSpeedRpt6f>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleSpeedRpt6f &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleSpeedRpt6f & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleSpeedRpt6f & dt);
}
