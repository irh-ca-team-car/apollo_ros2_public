#pragma once
#include "apollo_msgs/msg/apollocanbus_ads_brake_command46.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsBrakeCommand46 &msg) ;
    ApollocanbusAdsBrakeCommand46 from_json_ApollocanbusAdsBrakeCommand46 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdsBrakeCommand46 from_json<ApollocanbusAdsBrakeCommand46>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsBrakeCommand46 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsBrakeCommand46 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsBrakeCommand46 & dt);
}
