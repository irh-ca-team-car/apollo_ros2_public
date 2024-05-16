#pragma once
#include "apollo_msgs/msg/apollocanbus_wiper_aux_rpt334.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWiperAuxRpt334 &msg) ;
    ApollocanbusWiperAuxRpt334 from_json_ApollocanbusWiperAuxRpt334 (nlohmann::json obj) ;
    template <>
    ApollocanbusWiperAuxRpt334 from_json<ApollocanbusWiperAuxRpt334>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWiperAuxRpt334 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWiperAuxRpt334 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWiperAuxRpt334 & dt);
}
