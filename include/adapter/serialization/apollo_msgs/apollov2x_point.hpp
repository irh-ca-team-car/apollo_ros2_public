#pragma once
#include "apollo_msgs/msg/apollov2x_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xPoint &msg) ;
    Apollov2xPoint from_json_Apollov2xPoint (nlohmann::json obj) ;
    template <>
    Apollov2xPoint from_json<Apollov2xPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xPoint &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xPoint & dt);
}
