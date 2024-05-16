#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_diag_brakecontrol721.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcDiagBrakecontrol721 &msg) ;
    ApollocanbusLlcDiagBrakecontrol721 from_json_ApollocanbusLlcDiagBrakecontrol721 (nlohmann::json obj) ;
    template <>
    ApollocanbusLlcDiagBrakecontrol721 from_json<ApollocanbusLlcDiagBrakecontrol721>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcDiagBrakecontrol721 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcDiagBrakecontrol721 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcDiagBrakecontrol721 & dt);
}
