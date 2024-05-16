#pragma once
#include "apollo_msgs/msg/apollomonitor_system_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollomonitor_system_statushmi_modules.hpp"
#include "adapter/serialization/apollo_msgs/apollomonitor_system_statuscomponents.hpp"
#include "adapter/serialization/apollo_msgs/apollomonitor_system_statusother_components.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorSystemStatus &msg) ;
    ApollomonitorSystemStatus from_json_ApollomonitorSystemStatus (nlohmann::json obj) ;
    template <>
    ApollomonitorSystemStatus from_json<ApollomonitorSystemStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorSystemStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApollomonitorSystemStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorSystemStatus & dt);
}
