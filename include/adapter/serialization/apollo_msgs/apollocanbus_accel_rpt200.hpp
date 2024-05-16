#pragma once
#include "apollo_msgs/msg/apollocanbus_accel_rpt200.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAccelRpt200 &msg) ;
    ApollocanbusAccelRpt200 from_json_ApollocanbusAccelRpt200 (nlohmann::json obj) ;
    template <>
    ApollocanbusAccelRpt200 from_json<ApollocanbusAccelRpt200>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAccelRpt200 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAccelRpt200 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAccelRpt200 & dt);
}
