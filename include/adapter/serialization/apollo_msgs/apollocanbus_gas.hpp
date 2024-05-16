#pragma once
#include "apollo_msgs/msg/apollocanbus_gas.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGas &msg) ;
    ApollocanbusGas from_json_ApollocanbusGas (nlohmann::json obj) ;
    template <>
    ApollocanbusGas from_json<ApollocanbusGas>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGas &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGas & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGas & dt);
}
