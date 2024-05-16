#pragma once
#include "apollo_msgs/msg/apolloplanning_speed_decider_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_stop_time.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSpeedDeciderStatus &msg) ;
    ApolloplanningSpeedDeciderStatus from_json_ApolloplanningSpeedDeciderStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningSpeedDeciderStatus from_json<ApolloplanningSpeedDeciderStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSpeedDeciderStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSpeedDeciderStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSpeedDeciderStatus & dt);
}
