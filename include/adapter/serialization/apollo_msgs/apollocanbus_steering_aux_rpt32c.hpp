#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_aux_rpt32c.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringAuxRpt32c &msg) ;
    ApollocanbusSteeringAuxRpt32c from_json_ApollocanbusSteeringAuxRpt32c (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringAuxRpt32c from_json<ApollocanbusSteeringAuxRpt32c>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringAuxRpt32c &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringAuxRpt32c & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringAuxRpt32c & dt);
}
