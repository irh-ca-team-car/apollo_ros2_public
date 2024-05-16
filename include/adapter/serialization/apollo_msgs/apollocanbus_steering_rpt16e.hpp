#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_rpt16e.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringRpt16e &msg) ;
    ApollocanbusSteeringRpt16e from_json_ApollocanbusSteeringRpt16e (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringRpt16e from_json<ApollocanbusSteeringRpt16e>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringRpt16e &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringRpt16e & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringRpt16e & dt);
}
