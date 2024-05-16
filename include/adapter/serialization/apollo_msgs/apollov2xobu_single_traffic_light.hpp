#pragma once
#include "apollo_msgs/msg/apollov2xobu_single_traffic_light.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xobuSingleTrafficLight &msg) ;
    Apollov2xobuSingleTrafficLight from_json_Apollov2xobuSingleTrafficLight (nlohmann::json obj) ;
    template <>
    Apollov2xobuSingleTrafficLight from_json<Apollov2xobuSingleTrafficLight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xobuSingleTrafficLight &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xobuSingleTrafficLight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xobuSingleTrafficLight & dt);
}
