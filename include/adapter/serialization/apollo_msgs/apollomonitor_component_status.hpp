#pragma once
#include "apollo_msgs/msg/apollomonitor_component_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorComponentStatus &msg) ;
    ApollomonitorComponentStatus from_json_ApollomonitorComponentStatus (nlohmann::json obj) ;
    template <>
    ApollomonitorComponentStatus from_json<ApollomonitorComponentStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorComponentStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApollomonitorComponentStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorComponentStatus & dt);
}
