#pragma once
#include "apollo_msgs/msg/apollomonitor_system_statushmi_modules.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollomonitor_component_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorSystemStatushmiModules &msg) ;
    ApollomonitorSystemStatushmiModules from_json_ApollomonitorSystemStatushmiModules (nlohmann::json obj) ;
    template <>
    ApollomonitorSystemStatushmiModules from_json<ApollomonitorSystemStatushmiModules>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorSystemStatushmiModules &dt);
    std::ostream & operator<<(std::ostream & os, const ApollomonitorSystemStatushmiModules & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorSystemStatushmiModules & dt);
}
