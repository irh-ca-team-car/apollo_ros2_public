#pragma once
#include "apollo_msgs/msg/apollov2x_junction.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2x_id.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xJunction &msg) ;
    Apollov2xJunction from_json_Apollov2xJunction (nlohmann::json obj) ;
    template <>
    Apollov2xJunction from_json<Apollov2xJunction>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xJunction &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xJunction & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xJunction & dt);
}
