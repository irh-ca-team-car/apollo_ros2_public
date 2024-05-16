#pragma once
#include "apollo_msgs/msg/apollocanbus_wiper_cmd134.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWiperCmd134 &msg) ;
    ApollocanbusWiperCmd134 from_json_ApollocanbusWiperCmd134 (nlohmann::json obj) ;
    template <>
    ApollocanbusWiperCmd134 from_json<ApollocanbusWiperCmd134>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWiperCmd134 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWiperCmd134 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWiperCmd134 & dt);
}
