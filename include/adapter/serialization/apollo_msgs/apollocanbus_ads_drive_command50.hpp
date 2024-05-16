#pragma once
#include "apollo_msgs/msg/apollocanbus_ads_drive_command50.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsDriveCommand50 &msg) ;
    ApollocanbusAdsDriveCommand50 from_json_ApollocanbusAdsDriveCommand50 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdsDriveCommand50 from_json<ApollocanbusAdsDriveCommand50>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsDriveCommand50 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsDriveCommand50 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsDriveCommand50 & dt);
}
