#pragma once
#include "apollo_msgs/msg/apollodrivers_vehicle24f1.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle24f1 &msg) ;
    ApollodriversVehicle24f1 from_json_ApollodriversVehicle24f1 (nlohmann::json obj) ;
    template <>
    ApollodriversVehicle24f1 from_json<ApollodriversVehicle24f1>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle24f1 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle24f1 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle24f1 & dt);
}
