#pragma once
#include "apollo_msgs/msg/apollov2x_id.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xId &msg) ;
    Apollov2xId from_json_Apollov2xId (nlohmann::json obj) ;
    template <>
    Apollov2xId from_json<Apollov2xId>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xId &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xId & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xId & dt);
}
