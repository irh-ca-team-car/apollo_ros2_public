#pragma once
#include "apollo_msgs/msg/apollocanbus_gear_report503.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearReport503 &msg) ;
    ApollocanbusGearReport503 from_json_ApollocanbusGearReport503 (nlohmann::json obj) ;
    template <>
    ApollocanbusGearReport503 from_json<ApollocanbusGearReport503>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearReport503 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearReport503 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearReport503 & dt);
}
