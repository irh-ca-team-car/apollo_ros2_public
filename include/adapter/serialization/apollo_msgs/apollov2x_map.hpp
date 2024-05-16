#pragma once
#include "apollo_msgs/msg/apollov2x_map.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2x_intersection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xMap &msg) ;
    Apollov2xMap from_json_Apollov2xMap (nlohmann::json obj) ;
    template <>
    Apollov2xMap from_json<Apollov2xMap>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xMap &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xMap & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xMap & dt);
}
