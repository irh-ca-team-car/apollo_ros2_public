#pragma once
#include "apollo_msgs/msg/apollocanbus_vcu_drive_report52.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuDriveReport52 &msg) ;
    ApollocanbusVcuDriveReport52 from_json_ApollocanbusVcuDriveReport52 (nlohmann::json obj) ;
    template <>
    ApollocanbusVcuDriveReport52 from_json<ApollocanbusVcuDriveReport52>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuDriveReport52 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuDriveReport52 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuDriveReport52 & dt);
}
