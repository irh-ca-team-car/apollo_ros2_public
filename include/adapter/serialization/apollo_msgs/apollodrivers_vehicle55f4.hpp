#pragma once
#include "apollo_msgs/msg/apollodrivers_vehicle55f4.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle55f4 &msg) ;
    ApollodriversVehicle55f4 from_json_ApollodriversVehicle55f4 (nlohmann::json obj) ;
    template <>
    ApollodriversVehicle55f4 from_json<ApollodriversVehicle55f4>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle55f4 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle55f4 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle55f4 & dt);
}
