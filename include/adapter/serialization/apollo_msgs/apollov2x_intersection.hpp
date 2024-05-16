#pragma once
#include "apollo_msgs/msg/apollov2x_intersection.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2x_position2_d.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_road.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xIntersection &msg) ;
    Apollov2xIntersection from_json_Apollov2xIntersection (nlohmann::json obj) ;
    template <>
    Apollov2xIntersection from_json<Apollov2xIntersection>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xIntersection &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xIntersection & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xIntersection & dt);
}
