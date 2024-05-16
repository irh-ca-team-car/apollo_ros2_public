#pragma once
#include "apollo_msgs/msg/apolloplanning_object_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_object_motion_type.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectStatus &msg) ;
    ApolloplanningObjectStatus from_json_ApolloplanningObjectStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectStatus from_json<ApolloplanningObjectStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectStatus & dt);
}
