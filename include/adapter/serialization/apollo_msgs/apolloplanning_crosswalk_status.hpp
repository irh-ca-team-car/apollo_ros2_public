#pragma once
#include "apollo_msgs/msg/apolloplanning_crosswalk_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_stop_time.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCrosswalkStatus &msg) ;
    ApolloplanningCrosswalkStatus from_json_ApolloplanningCrosswalkStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningCrosswalkStatus from_json<ApolloplanningCrosswalkStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCrosswalkStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCrosswalkStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCrosswalkStatus & dt);
}
