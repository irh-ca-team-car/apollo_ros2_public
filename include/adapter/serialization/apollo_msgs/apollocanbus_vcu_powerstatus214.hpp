#pragma once
#include "apollo_msgs/msg/apollocanbus_vcu_powerstatus214.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuPowerstatus214 &msg) ;
    ApollocanbusVcuPowerstatus214 from_json_ApollocanbusVcuPowerstatus214 (nlohmann::json obj) ;
    template <>
    ApollocanbusVcuPowerstatus214 from_json<ApollocanbusVcuPowerstatus214>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuPowerstatus214 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuPowerstatus214 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuPowerstatus214 & dt);
}
