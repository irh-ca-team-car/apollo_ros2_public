#pragma once
#include "apollo_msgs/msg/apollocanbus_vcu_report505.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuReport505 &msg) ;
    ApollocanbusVcuReport505 from_json_ApollocanbusVcuReport505 (nlohmann::json obj) ;
    template <>
    ApollocanbusVcuReport505 from_json<ApollocanbusVcuReport505>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuReport505 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuReport505 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuReport505 & dt);
}
