#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_rpt22c.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringRpt22c &msg) ;
    ApollocanbusSteeringRpt22c from_json_ApollocanbusSteeringRpt22c (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringRpt22c from_json<ApollocanbusSteeringRpt22c>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringRpt22c &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringRpt22c & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringRpt22c & dt);
}
