#pragma once
#include "apollo_msgs/msg/apollocanbus_vehicle_spd.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleSpd &msg) ;
    ApollocanbusVehicleSpd from_json_ApollocanbusVehicleSpd (nlohmann::json obj) ;
    template <>
    ApollocanbusVehicleSpd from_json<ApollocanbusVehicleSpd>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleSpd &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleSpd & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleSpd & dt);
}
