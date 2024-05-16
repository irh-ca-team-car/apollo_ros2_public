#pragma once
#include "apollo_msgs/msg/apollocanbus_media_controls_rpt220.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusMediaControlsRpt220 &msg) ;
    ApollocanbusMediaControlsRpt220 from_json_ApollocanbusMediaControlsRpt220 (nlohmann::json obj) ;
    template <>
    ApollocanbusMediaControlsRpt220 from_json<ApollocanbusMediaControlsRpt220>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusMediaControlsRpt220 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusMediaControlsRpt220 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusMediaControlsRpt220 & dt);
}
