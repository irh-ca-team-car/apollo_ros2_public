#pragma once
#include "apollo_msgs/msg/apollocanbus_vcu_vehicle_fault_response201.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuVehicleFaultResponse201 &msg) ;
    ApollocanbusVcuVehicleFaultResponse201 from_json_ApollocanbusVcuVehicleFaultResponse201 (nlohmann::json obj) ;
    template <>
    ApollocanbusVcuVehicleFaultResponse201 from_json<ApollocanbusVcuVehicleFaultResponse201>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuVehicleFaultResponse201 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuVehicleFaultResponse201 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuVehicleFaultResponse201 & dt);
}
