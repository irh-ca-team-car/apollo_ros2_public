#pragma once
#include "apollo_msgs/msg/apollocanbus_global_rpt6a.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGlobalRpt6a &msg) ;
    ApollocanbusGlobalRpt6a from_json_ApollocanbusGlobalRpt6a (nlohmann::json obj) ;
    template <>
    ApollocanbusGlobalRpt6a from_json<ApollocanbusGlobalRpt6a>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGlobalRpt6a &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGlobalRpt6a & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGlobalRpt6a & dt);
}
