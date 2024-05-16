#pragma once
#include "apollo_msgs/msg/apollocanbus_vehicle_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleParameter &msg) ;
    ApollocanbusVehicleParameter from_json_ApollocanbusVehicleParameter (nlohmann::json obj) ;
    template <>
    ApollocanbusVehicleParameter from_json<ApollocanbusVehicleParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleParameter & dt);
}
