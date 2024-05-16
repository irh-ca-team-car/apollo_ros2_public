#pragma once
#include "apollo_msgs/msg/apollorouting_routing_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_topic_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingRoutingConfig &msg) ;
    ApolloroutingRoutingConfig from_json_ApolloroutingRoutingConfig (nlohmann::json obj) ;
    template <>
    ApolloroutingRoutingConfig from_json<ApolloroutingRoutingConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingRoutingConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingRoutingConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingRoutingConfig & dt);
}
