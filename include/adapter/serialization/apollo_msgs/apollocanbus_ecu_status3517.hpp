#pragma once
#include "apollo_msgs/msg/apollocanbus_ecu_status3517.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEcuStatus3517 &msg) ;
    ApollocanbusEcuStatus3517 from_json_ApollocanbusEcuStatus3517 (nlohmann::json obj) ;
    template <>
    ApollocanbusEcuStatus3517 from_json<ApollocanbusEcuStatus3517>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEcuStatus3517 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEcuStatus3517 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEcuStatus3517 & dt);
}
