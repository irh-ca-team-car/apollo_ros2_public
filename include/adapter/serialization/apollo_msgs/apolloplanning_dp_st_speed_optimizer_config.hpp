#pragma once
#include "apollo_msgs/msg/apolloplanning_dp_st_speed_optimizer_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDpStSpeedOptimizerConfig &msg) ;
    ApolloplanningDpStSpeedOptimizerConfig from_json_ApolloplanningDpStSpeedOptimizerConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningDpStSpeedOptimizerConfig from_json<ApolloplanningDpStSpeedOptimizerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDpStSpeedOptimizerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDpStSpeedOptimizerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDpStSpeedOptimizerConfig & dt);
}
