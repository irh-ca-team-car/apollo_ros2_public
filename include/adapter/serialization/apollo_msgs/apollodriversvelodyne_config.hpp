#pragma once
#include "apollo_msgs/msg/apollodriversvelodyne_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneConfig &msg) ;
    ApollodriversvelodyneConfig from_json_ApollodriversvelodyneConfig (nlohmann::json obj) ;
    template <>
    ApollodriversvelodyneConfig from_json<ApollodriversvelodyneConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneConfig & dt);
}
