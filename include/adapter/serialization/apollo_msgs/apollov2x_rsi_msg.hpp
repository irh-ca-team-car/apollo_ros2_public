#pragma once
#include "apollo_msgs/msg/apollov2x_rsi_msg.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_rsi_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xRsiMsg &msg) ;
    Apollov2xRsiMsg from_json_Apollov2xRsiMsg (nlohmann::json obj) ;
    template <>
    Apollov2xRsiMsg from_json<Apollov2xRsiMsg>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xRsiMsg &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xRsiMsg & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xRsiMsg & dt);
}
