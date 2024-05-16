#pragma once
#include "apollo_msgs/msg/apollodrivers_vehicle35f2.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle35f2 &msg) ;
    ApollodriversVehicle35f2 from_json_ApollodriversVehicle35f2 (nlohmann::json obj) ;
    template <>
    ApollodriversVehicle35f2 from_json<ApollodriversVehicle35f2>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle35f2 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle35f2 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle35f2 & dt);
}
