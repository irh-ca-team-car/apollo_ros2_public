#pragma once
#include "apollo_msgs/msg/apollocanbus_check_response_signal.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusCheckResponseSignal &msg) ;
    ApollocanbusCheckResponseSignal from_json_ApollocanbusCheckResponseSignal (nlohmann::json obj) ;
    template <>
    ApollocanbusCheckResponseSignal from_json<ApollocanbusCheckResponseSignal>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusCheckResponseSignal &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusCheckResponseSignal & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusCheckResponseSignal & dt);
}
