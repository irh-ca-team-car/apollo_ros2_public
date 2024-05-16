#pragma once
#include "apollo_msgs/msg/apolloplanning_warm_start_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_speed_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningWarmStartConfig &msg) ;
    ApolloplanningWarmStartConfig from_json_ApolloplanningWarmStartConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningWarmStartConfig from_json<ApolloplanningWarmStartConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningWarmStartConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningWarmStartConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningWarmStartConfig & dt);
}
