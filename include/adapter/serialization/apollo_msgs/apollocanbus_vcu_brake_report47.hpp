#pragma once
#include "apollo_msgs/msg/apollocanbus_vcu_brake_report47.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuBrakeReport47 &msg) ;
    ApollocanbusVcuBrakeReport47 from_json_ApollocanbusVcuBrakeReport47 (nlohmann::json obj) ;
    template <>
    ApollocanbusVcuBrakeReport47 from_json<ApollocanbusVcuBrakeReport47>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuBrakeReport47 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuBrakeReport47 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuBrakeReport47 & dt);
}
