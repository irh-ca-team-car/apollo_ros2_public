#pragma once
#include "apollo_msgs/msg/apollomonitor_system_statusother_components.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollomonitor_component_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorSystemStatusotherComponents &msg) ;
    ApollomonitorSystemStatusotherComponents from_json_ApollomonitorSystemStatusotherComponents (nlohmann::json obj) ;
    template <>
    ApollomonitorSystemStatusotherComponents from_json<ApollomonitorSystemStatusotherComponents>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorSystemStatusotherComponents &dt);
    std::ostream & operator<<(std::ostream & os, const ApollomonitorSystemStatusotherComponents & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorSystemStatusotherComponents & dt);
}
