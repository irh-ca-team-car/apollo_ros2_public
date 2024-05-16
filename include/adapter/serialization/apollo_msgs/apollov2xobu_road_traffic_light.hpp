#pragma once
#include "apollo_msgs/msg/apollov2xobu_road_traffic_light.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2xobu_lane_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xobuRoadTrafficLight &msg) ;
    Apollov2xobuRoadTrafficLight from_json_Apollov2xobuRoadTrafficLight (nlohmann::json obj) ;
    template <>
    Apollov2xobuRoadTrafficLight from_json<Apollov2xobuRoadTrafficLight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xobuRoadTrafficLight &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xobuRoadTrafficLight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xobuRoadTrafficLight & dt);
}
