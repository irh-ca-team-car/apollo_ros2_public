#pragma once
#include "apollo_msgs/msg/apollocanbus_ecu_status1515.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEcuStatus1515 &msg) ;
    ApollocanbusEcuStatus1515 from_json_ApollocanbusEcuStatus1515 (nlohmann::json obj) ;
    template <>
    ApollocanbusEcuStatus1515 from_json<ApollocanbusEcuStatus1515>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEcuStatus1515 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEcuStatus1515 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEcuStatus1515 & dt);
}
