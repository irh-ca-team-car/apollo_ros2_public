#pragma once
#include "apollo_msgs/msg/apollocanbus_global_rpt10.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGlobalRpt10 &msg) ;
    ApollocanbusGlobalRpt10 from_json_ApollocanbusGlobalRpt10 (nlohmann::json obj) ;
    template <>
    ApollocanbusGlobalRpt10 from_json<ApollocanbusGlobalRpt10>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGlobalRpt10 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGlobalRpt10 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGlobalRpt10 & dt);
}
