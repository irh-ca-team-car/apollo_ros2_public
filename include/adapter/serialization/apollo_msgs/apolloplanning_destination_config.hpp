#pragma once
#include "apollo_msgs/msg/apolloplanning_destination_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDestinationConfig &msg) ;
    ApolloplanningDestinationConfig from_json_ApolloplanningDestinationConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningDestinationConfig from_json<ApolloplanningDestinationConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDestinationConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDestinationConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDestinationConfig & dt);
}
