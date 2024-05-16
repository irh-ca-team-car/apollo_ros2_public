#pragma once
#include "apollo_msgs/msg/apollodrivers_vehicle45f3.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle45f3 &msg) ;
    ApollodriversVehicle45f3 from_json_ApollodriversVehicle45f3 (nlohmann::json obj) ;
    template <>
    ApollodriversVehicle45f3 from_json<ApollodriversVehicle45f3>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle45f3 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle45f3 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle45f3 & dt);
}
