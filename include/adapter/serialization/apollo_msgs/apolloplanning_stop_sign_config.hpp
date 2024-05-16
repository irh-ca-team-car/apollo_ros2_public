#pragma once
#include "apollo_msgs/msg/apolloplanning_stop_sign_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStopSignConfig &msg) ;
    ApolloplanningStopSignConfig from_json_ApolloplanningStopSignConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningStopSignConfig from_json<ApolloplanningStopSignConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStopSignConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStopSignConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStopSignConfig & dt);
}
