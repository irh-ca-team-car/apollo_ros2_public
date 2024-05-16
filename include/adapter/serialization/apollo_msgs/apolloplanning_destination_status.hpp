#pragma once
#include "apollo_msgs/msg/apolloplanning_destination_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDestinationStatus &msg) ;
    ApolloplanningDestinationStatus from_json_ApolloplanningDestinationStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningDestinationStatus from_json<ApolloplanningDestinationStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDestinationStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDestinationStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDestinationStatus & dt);
}
