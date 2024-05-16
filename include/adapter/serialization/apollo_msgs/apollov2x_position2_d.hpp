#pragma once
#include "apollo_msgs/msg/apollov2x_position2_d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xPosition2D &msg) ;
    Apollov2xPosition2D from_json_Apollov2xPosition2D (nlohmann::json obj) ;
    template <>
    Apollov2xPosition2D from_json<Apollov2xPosition2D>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xPosition2D &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xPosition2D & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xPosition2D & dt);
}
