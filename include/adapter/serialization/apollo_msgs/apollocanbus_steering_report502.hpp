#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_report502.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringReport502 &msg) ;
    ApollocanbusSteeringReport502 from_json_ApollocanbusSteeringReport502 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringReport502 from_json<ApollocanbusSteeringReport502>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringReport502 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringReport502 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringReport502 & dt);
}
