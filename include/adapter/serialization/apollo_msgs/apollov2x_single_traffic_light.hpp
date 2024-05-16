#pragma once
#include "apollo_msgs/msg/apollov2x_single_traffic_light.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xSingleTrafficLight &msg) ;
    Apollov2xSingleTrafficLight from_json_Apollov2xSingleTrafficLight (nlohmann::json obj) ;
    template <>
    Apollov2xSingleTrafficLight from_json<Apollov2xSingleTrafficLight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xSingleTrafficLight &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xSingleTrafficLight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xSingleTrafficLight & dt);
}
