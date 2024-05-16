#pragma once
#include "apollo_msgs/msg/apollocanbus_vcu_vehicle_info_response502.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuVehicleInfoResponse502 &msg) ;
    ApollocanbusVcuVehicleInfoResponse502 from_json_ApollocanbusVcuVehicleInfoResponse502 (nlohmann::json obj) ;
    template <>
    ApollocanbusVcuVehicleInfoResponse502 from_json<ApollocanbusVcuVehicleInfoResponse502>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuVehicleInfoResponse502 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuVehicleInfoResponse502 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuVehicleInfoResponse502 & dt);
}
