#pragma once
#include "apollo_msgs/msg/apollodrivers_vehicle14f0.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle14f0 &msg) ;
    ApollodriversVehicle14f0 from_json_ApollodriversVehicle14f0 (nlohmann::json obj) ;
    template <>
    ApollodriversVehicle14f0 from_json<ApollodriversVehicle14f0>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle14f0 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle14f0 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle14f0 & dt);
}
