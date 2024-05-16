#pragma once
#include "apollo_msgs/msg/apollov2x_road_traffic_light.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2x_single_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xRoadTrafficLight &msg) ;
    Apollov2xRoadTrafficLight from_json_Apollov2xRoadTrafficLight (nlohmann::json obj) ;
    template <>
    Apollov2xRoadTrafficLight from_json<Apollov2xRoadTrafficLight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xRoadTrafficLight &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xRoadTrafficLight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xRoadTrafficLight & dt);
}
