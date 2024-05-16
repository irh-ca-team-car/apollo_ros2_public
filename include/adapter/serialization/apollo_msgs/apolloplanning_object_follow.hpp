#pragma once
#include "apollo_msgs/msg/apolloplanning_object_follow.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectFollow &msg) ;
    ApolloplanningObjectFollow from_json_ApolloplanningObjectFollow (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectFollow from_json<ApolloplanningObjectFollow>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectFollow &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectFollow & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectFollow & dt);
}
