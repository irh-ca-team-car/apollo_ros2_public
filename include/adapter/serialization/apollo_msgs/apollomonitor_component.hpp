#pragma once
#include "apollo_msgs/msg/apollomonitor_component.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollomonitor_component_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorComponent &msg) ;
    ApollomonitorComponent from_json_ApollomonitorComponent (nlohmann::json obj) ;
    template <>
    ApollomonitorComponent from_json<ApollomonitorComponent>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorComponent &dt);
    std::ostream & operator<<(std::ostream & os, const ApollomonitorComponent & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorComponent & dt);
}
