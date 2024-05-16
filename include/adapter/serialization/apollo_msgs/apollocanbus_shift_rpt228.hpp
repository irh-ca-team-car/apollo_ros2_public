#pragma once
#include "apollo_msgs/msg/apollocanbus_shift_rpt228.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusShiftRpt228 &msg) ;
    ApollocanbusShiftRpt228 from_json_ApollocanbusShiftRpt228 (nlohmann::json obj) ;
    template <>
    ApollocanbusShiftRpt228 from_json<ApollocanbusShiftRpt228>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusShiftRpt228 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusShiftRpt228 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusShiftRpt228 & dt);
}
