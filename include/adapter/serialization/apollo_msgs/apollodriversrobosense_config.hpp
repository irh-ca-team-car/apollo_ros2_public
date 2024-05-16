#pragma once
#include "apollo_msgs/msg/apollodriversrobosense_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversrobosenseConfig &msg) ;
    ApollodriversrobosenseConfig from_json_ApollodriversrobosenseConfig (nlohmann::json obj) ;
    template <>
    ApollodriversrobosenseConfig from_json<ApollodriversrobosenseConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversrobosenseConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversrobosenseConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversrobosenseConfig & dt);
}
