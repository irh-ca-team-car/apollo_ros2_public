#pragma once
#include "apollo_msgs/msg/apollov2xobu_obu_traffic_light.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xobu_road_traffic_light.hpp"
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xobuObuTrafficLight &msg) ;
    Apollov2xobuObuTrafficLight from_json_Apollov2xobuObuTrafficLight (nlohmann::json obj) ;
    template <>
    Apollov2xobuObuTrafficLight from_json<Apollov2xobuObuTrafficLight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xobuObuTrafficLight &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xobuObuTrafficLight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xobuObuTrafficLight & dt);
}
