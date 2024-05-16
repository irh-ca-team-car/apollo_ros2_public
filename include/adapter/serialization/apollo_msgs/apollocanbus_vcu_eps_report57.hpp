#pragma once
#include "apollo_msgs/msg/apollocanbus_vcu_eps_report57.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuEpsReport57 &msg) ;
    ApollocanbusVcuEpsReport57 from_json_ApollocanbusVcuEpsReport57 (nlohmann::json obj) ;
    template <>
    ApollocanbusVcuEpsReport57 from_json<ApollocanbusVcuEpsReport57>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuEpsReport57 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuEpsReport57 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuEpsReport57 & dt);
}
