#pragma once
#include "apollo_msgs/msg/apolloplanning_object_nudge.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectNudge &msg) ;
    ApolloplanningObjectNudge from_json_ApolloplanningObjectNudge (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectNudge from_json<ApolloplanningObjectNudge>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectNudge &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectNudge & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectNudge & dt);
}
