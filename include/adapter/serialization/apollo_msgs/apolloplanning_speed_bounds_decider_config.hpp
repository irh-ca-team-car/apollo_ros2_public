#pragma once
#include "apollo_msgs/msg/apolloplanning_speed_bounds_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSpeedBoundsDeciderConfig &msg) ;
    ApolloplanningSpeedBoundsDeciderConfig from_json_ApolloplanningSpeedBoundsDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningSpeedBoundsDeciderConfig from_json<ApolloplanningSpeedBoundsDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSpeedBoundsDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSpeedBoundsDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSpeedBoundsDeciderConfig & dt);
}
