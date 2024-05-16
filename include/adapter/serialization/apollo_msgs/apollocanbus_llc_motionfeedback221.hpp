#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_motionfeedback221.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcMotionfeedback221 &msg) ;
    ApollocanbusLlcMotionfeedback221 from_json_ApollocanbusLlcMotionfeedback221 (nlohmann::json obj) ;
    template <>
    ApollocanbusLlcMotionfeedback221 from_json<ApollocanbusLlcMotionfeedback221>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcMotionfeedback221 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcMotionfeedback221 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcMotionfeedback221 & dt);
}
