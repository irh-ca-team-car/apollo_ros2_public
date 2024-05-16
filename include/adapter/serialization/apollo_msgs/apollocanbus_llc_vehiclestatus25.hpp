#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_vehiclestatus25.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcVehiclestatus25 &msg) ;
    ApollocanbusLlcVehiclestatus25 from_json_ApollocanbusLlcVehiclestatus25 (nlohmann::json obj) ;
    template <>
    ApollocanbusLlcVehiclestatus25 from_json<ApollocanbusLlcVehiclestatus25>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcVehiclestatus25 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcVehiclestatus25 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcVehiclestatus25 & dt);
}
