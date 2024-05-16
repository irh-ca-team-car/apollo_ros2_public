#pragma once
#include "apollo_msgs/msg/apollocanbus_media_controls_cmd120.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusMediaControlsCmd120 &msg) ;
    ApollocanbusMediaControlsCmd120 from_json_ApollocanbusMediaControlsCmd120 (nlohmann::json obj) ;
    template <>
    ApollocanbusMediaControlsCmd120 from_json<ApollocanbusMediaControlsCmd120>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusMediaControlsCmd120 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusMediaControlsCmd120 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusMediaControlsCmd120 & dt);
}
