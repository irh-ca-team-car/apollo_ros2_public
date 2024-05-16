#pragma once
#include "apollo_msgs/msg/apollocanbus_eps.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEps &msg) ;
    ApollocanbusEps from_json_ApollocanbusEps (nlohmann::json obj) ;
    template <>
    ApollocanbusEps from_json<ApollocanbusEps>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEps &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEps & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEps & dt);
}
