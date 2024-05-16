#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_auxiliaryfeedback120.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcAuxiliaryfeedback120 &msg) ;
    ApollocanbusLlcAuxiliaryfeedback120 from_json_ApollocanbusLlcAuxiliaryfeedback120 (nlohmann::json obj) ;
    template <>
    ApollocanbusLlcAuxiliaryfeedback120 from_json<ApollocanbusLlcAuxiliaryfeedback120>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcAuxiliaryfeedback120 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcAuxiliaryfeedback120 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcAuxiliaryfeedback120 & dt);
}
