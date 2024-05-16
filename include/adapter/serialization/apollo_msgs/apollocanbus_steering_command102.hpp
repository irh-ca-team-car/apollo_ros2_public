#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_command102.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringCommand102 &msg) ;
    ApollocanbusSteeringCommand102 from_json_ApollocanbusSteeringCommand102 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringCommand102 from_json<ApollocanbusSteeringCommand102>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringCommand102 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringCommand102 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringCommand102 & dt);
}
