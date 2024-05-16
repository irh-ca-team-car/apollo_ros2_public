#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_diag_steeringcontrol722.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcDiagSteeringcontrol722 &msg) ;
    ApollocanbusLlcDiagSteeringcontrol722 from_json_ApollocanbusLlcDiagSteeringcontrol722 (nlohmann::json obj) ;
    template <>
    ApollocanbusLlcDiagSteeringcontrol722 from_json<ApollocanbusLlcDiagSteeringcontrol722>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcDiagSteeringcontrol722 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcDiagSteeringcontrol722 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcDiagSteeringcontrol722 & dt);
}
