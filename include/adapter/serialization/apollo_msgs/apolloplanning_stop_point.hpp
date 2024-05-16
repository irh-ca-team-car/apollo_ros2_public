#pragma once
#include "apollo_msgs/msg/apolloplanning_stop_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStopPoint &msg) ;
    ApolloplanningStopPoint from_json_ApolloplanningStopPoint (nlohmann::json obj) ;
    template <>
    ApolloplanningStopPoint from_json<ApolloplanningStopPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStopPoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStopPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStopPoint & dt);
}
