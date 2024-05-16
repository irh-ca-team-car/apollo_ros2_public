#pragma once
#include "apollo_msgs/msg/apollocanbus_shift_cmd65.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusShiftCmd65 &msg) ;
    ApollocanbusShiftCmd65 from_json_ApollocanbusShiftCmd65 (nlohmann::json obj) ;
    template <>
    ApollocanbusShiftCmd65 from_json<ApollocanbusShiftCmd65>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusShiftCmd65 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusShiftCmd65 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusShiftCmd65 & dt);
}
