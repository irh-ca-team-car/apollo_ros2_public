#pragma once
#include "apollo_msgs/msg/apollov2x_mini_area_map.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xMiniAreaMap &msg) ;
    Apollov2xMiniAreaMap from_json_Apollov2xMiniAreaMap (nlohmann::json obj) ;
    template <>
    Apollov2xMiniAreaMap from_json<Apollov2xMiniAreaMap>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xMiniAreaMap &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xMiniAreaMap & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xMiniAreaMap & dt);
}
