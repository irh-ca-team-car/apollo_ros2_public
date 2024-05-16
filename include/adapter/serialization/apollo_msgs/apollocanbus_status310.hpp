#pragma once
#include "apollo_msgs/msg/apollocanbus_status310.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusStatus310 &msg) ;
    ApollocanbusStatus310 from_json_ApollocanbusStatus310 (nlohmann::json obj) ;
    template <>
    ApollocanbusStatus310 from_json<ApollocanbusStatus310>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusStatus310 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusStatus310 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusStatus310 & dt);
}
