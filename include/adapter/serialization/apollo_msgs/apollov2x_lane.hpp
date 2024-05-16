#pragma once
#include "apollo_msgs/msg/apollov2x_lane.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2x_position2_d.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_connection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xLane &msg) ;
    Apollov2xLane from_json_Apollov2xLane (nlohmann::json obj) ;
    template <>
    Apollov2xLane from_json<Apollov2xLane>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xLane &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xLane & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xLane & dt);
}
