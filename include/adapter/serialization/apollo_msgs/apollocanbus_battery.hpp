#pragma once
#include "apollo_msgs/msg/apollocanbus_battery.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBattery &msg) ;
    ApollocanbusBattery from_json_ApollocanbusBattery (nlohmann::json obj) ;
    template <>
    ApollocanbusBattery from_json<ApollocanbusBattery>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBattery &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBattery & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBattery & dt);
}
