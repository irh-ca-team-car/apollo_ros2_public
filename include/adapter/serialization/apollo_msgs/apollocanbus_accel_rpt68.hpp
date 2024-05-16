#pragma once
#include "apollo_msgs/msg/apollocanbus_accel_rpt68.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAccelRpt68 &msg) ;
    ApollocanbusAccelRpt68 from_json_ApollocanbusAccelRpt68 (nlohmann::json obj) ;
    template <>
    ApollocanbusAccelRpt68 from_json<ApollocanbusAccelRpt68>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAccelRpt68 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAccelRpt68 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAccelRpt68 & dt);
}
