#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_state.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollolocalization_pose.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleState &msg) ;
    ApollocommonVehicleState from_json_ApollocommonVehicleState (nlohmann::json obj) ;
    template <>
    ApollocommonVehicleState from_json<ApollocommonVehicleState>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleState &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleState & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleState & dt);
}
