#pragma once
#include "apollo_msgs/msg/apollov2x_rsi_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xRsiPoint &msg) ;
    Apollov2xRsiPoint from_json_Apollov2xRsiPoint (nlohmann::json obj) ;
    template <>
    Apollov2xRsiPoint from_json<Apollov2xRsiPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xRsiPoint &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xRsiPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xRsiPoint & dt);
}
