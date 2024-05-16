#pragma once
#include "apollo_msgs/msg/apolloplanning_stop_sign_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStopSignStatus &msg) ;
    ApolloplanningStopSignStatus from_json_ApolloplanningStopSignStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningStopSignStatus from_json<ApolloplanningStopSignStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStopSignStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStopSignStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStopSignStatus & dt);
}
