#pragma once
#include "apollo_msgs/msg/apollocanbus_shift_rpt66.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusShiftRpt66 &msg) ;
    ApollocanbusShiftRpt66 from_json_ApollocanbusShiftRpt66 (nlohmann::json obj) ;
    template <>
    ApollocanbusShiftRpt66 from_json<ApollocanbusShiftRpt66>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusShiftRpt66 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusShiftRpt66 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusShiftRpt66 & dt);
}
