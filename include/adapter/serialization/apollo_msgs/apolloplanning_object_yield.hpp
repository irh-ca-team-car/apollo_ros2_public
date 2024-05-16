#pragma once
#include "apollo_msgs/msg/apolloplanning_object_yield.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectYield &msg) ;
    ApolloplanningObjectYield from_json_ApolloplanningObjectYield (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectYield from_json<ApolloplanningObjectYield>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectYield &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectYield & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectYield & dt);
}
