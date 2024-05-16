#pragma once
#include "apollo_msgs/msg/channels.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/channel_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Channels &msg) ;
    Channels from_json_Channels (nlohmann::json obj) ;
    template <>
    Channels from_json<Channels>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Channels &dt);
    std::ostream & operator<<(std::ostream & os, const Channels & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Channels & dt);
}
