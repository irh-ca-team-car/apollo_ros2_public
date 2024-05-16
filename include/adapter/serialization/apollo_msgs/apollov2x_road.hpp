#pragma once
#include "apollo_msgs/msg/apollov2x_road.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2x_position2_d.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_lane.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xRoad &msg) ;
    Apollov2xRoad from_json_Apollov2xRoad (nlohmann::json obj) ;
    template <>
    Apollov2xRoad from_json<Apollov2xRoad>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xRoad &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xRoad & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xRoad & dt);
}
