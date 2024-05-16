#pragma once
#include "apollo_msgs/msg/apolloplanning_emergency_stop_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningEmergencyStopStatus &msg) ;
    ApolloplanningEmergencyStopStatus from_json_ApolloplanningEmergencyStopStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningEmergencyStopStatus from_json<ApolloplanningEmergencyStopStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningEmergencyStopStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningEmergencyStopStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningEmergencyStopStatus & dt);
}
