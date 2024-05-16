#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_id.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleID &msg) ;
    ApollocommonVehicleID from_json_ApollocommonVehicleID (nlohmann::json obj) ;
    template <>
    ApollocommonVehicleID from_json<ApollocommonVehicleID>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleID &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleID & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleID & dt);
}
