#pragma once
#include "apollo_msgs/msg/apollocanbus_ecu_status2516.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEcuStatus2516 &msg) ;
    ApollocanbusEcuStatus2516 from_json_ApollocanbusEcuStatus2516 (nlohmann::json obj) ;
    template <>
    ApollocanbusEcuStatus2516 from_json<ApollocanbusEcuStatus2516>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEcuStatus2516 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEcuStatus2516 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEcuStatus2516 & dt);
}
