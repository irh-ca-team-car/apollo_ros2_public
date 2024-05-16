#pragma once
#include "apollo_msgs/msg/apollov2x_spat.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2x_intersection_state.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xSpat &msg) ;
    Apollov2xSpat from_json_Apollov2xSpat (nlohmann::json obj) ;
    template <>
    Apollov2xSpat from_json<Apollov2xSpat>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xSpat &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xSpat & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xSpat & dt);
}
