#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_signal.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleSignal &msg) ;
    ApollocommonVehicleSignal from_json_ApollocommonVehicleSignal (nlohmann::json obj) ;
    template <>
    ApollocommonVehicleSignal from_json<ApollocommonVehicleSignal>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleSignal &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleSignal & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleSignal & dt);
}
