#pragma once
#include "apollo_msgs/msg/apollocanbus_yaw_rate_rpt40d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusYawRateRpt40d &msg) ;
    ApollocanbusYawRateRpt40d from_json_ApollocanbusYawRateRpt40d (nlohmann::json obj) ;
    template <>
    ApollocanbusYawRateRpt40d from_json<ApollocanbusYawRateRpt40d>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusYawRateRpt40d &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusYawRateRpt40d & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusYawRateRpt40d & dt);
}
