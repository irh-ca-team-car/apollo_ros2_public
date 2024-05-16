#pragma once
#include "apollo_msgs/msg/apollodriversvelodyne_compensator_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneCompensatorConfig &msg) ;
    ApollodriversvelodyneCompensatorConfig from_json_ApollodriversvelodyneCompensatorConfig (nlohmann::json obj) ;
    template <>
    ApollodriversvelodyneCompensatorConfig from_json<ApollodriversvelodyneCompensatorConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneCompensatorConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneCompensatorConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneCompensatorConfig & dt);
}
