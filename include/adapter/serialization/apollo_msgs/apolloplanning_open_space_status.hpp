#pragma once
#include "apollo_msgs/msg/apolloplanning_open_space_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceStatus &msg) ;
    ApolloplanningOpenSpaceStatus from_json_ApolloplanningOpenSpaceStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningOpenSpaceStatus from_json<ApolloplanningOpenSpaceStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceStatus & dt);
}
