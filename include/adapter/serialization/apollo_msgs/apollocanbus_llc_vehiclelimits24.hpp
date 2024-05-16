#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_vehiclelimits24.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcVehiclelimits24 &msg) ;
    ApollocanbusLlcVehiclelimits24 from_json_ApollocanbusLlcVehiclelimits24 (nlohmann::json obj) ;
    template <>
    ApollocanbusLlcVehiclelimits24 from_json<ApollocanbusLlcVehiclelimits24>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcVehiclelimits24 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcVehiclelimits24 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcVehiclelimits24 & dt);
}
