#pragma once
#include "apollo_msgs/msg/apollocanbus_yaw_rate_rpt81.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusYawRateRpt81 &msg) ;
    ApollocanbusYawRateRpt81 from_json_ApollocanbusYawRateRpt81 (nlohmann::json obj) ;
    template <>
    ApollocanbusYawRateRpt81 from_json<ApollocanbusYawRateRpt81>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusYawRateRpt81 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusYawRateRpt81 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusYawRateRpt81 & dt);
}
