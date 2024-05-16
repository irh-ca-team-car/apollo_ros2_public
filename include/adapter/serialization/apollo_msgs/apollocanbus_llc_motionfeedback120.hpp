#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_motionfeedback120.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcMotionfeedback120 &msg) ;
    ApollocanbusLlcMotionfeedback120 from_json_ApollocanbusLlcMotionfeedback120 (nlohmann::json obj) ;
    template <>
    ApollocanbusLlcMotionfeedback120 from_json<ApollocanbusLlcMotionfeedback120>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcMotionfeedback120 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcMotionfeedback120 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcMotionfeedback120 & dt);
}
