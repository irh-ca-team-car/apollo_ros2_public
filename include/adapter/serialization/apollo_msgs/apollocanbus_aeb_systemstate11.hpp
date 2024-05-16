#pragma once
#include "apollo_msgs/msg/apollocanbus_aeb_systemstate11.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebSystemstate11 &msg) ;
    ApollocanbusAebSystemstate11 from_json_ApollocanbusAebSystemstate11 (nlohmann::json obj) ;
    template <>
    ApollocanbusAebSystemstate11 from_json<ApollocanbusAebSystemstate11>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebSystemstate11 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebSystemstate11 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebSystemstate11 & dt);
}
