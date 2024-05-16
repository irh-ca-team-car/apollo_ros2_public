#pragma once
#include "apollo_msgs/msg/radar_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/vector3.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const RadarPoint &msg) ;
    RadarPoint from_json_RadarPoint (nlohmann::json obj) ;
    template <>
    RadarPoint from_json<RadarPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, RadarPoint &dt);
    std::ostream & operator<<(std::ostream & os, const RadarPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const RadarPoint & dt);
}
