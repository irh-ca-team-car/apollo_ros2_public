#pragma once
#include "apollo_msgs/msg/apolloplanning_backside_vehicle_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningBacksideVehicleConfig &msg) ;
    ApolloplanningBacksideVehicleConfig from_json_ApolloplanningBacksideVehicleConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningBacksideVehicleConfig from_json<ApolloplanningBacksideVehicleConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningBacksideVehicleConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningBacksideVehicleConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningBacksideVehicleConfig & dt);
}
