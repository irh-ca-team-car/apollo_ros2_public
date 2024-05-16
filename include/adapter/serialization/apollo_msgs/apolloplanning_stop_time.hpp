#pragma once
#include "apollo_msgs/msg/apolloplanning_stop_time.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStopTime &msg) ;
    ApolloplanningStopTime from_json_ApolloplanningStopTime (nlohmann::json obj) ;
    template <>
    ApolloplanningStopTime from_json<ApolloplanningStopTime>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStopTime &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStopTime & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStopTime & dt);
}
