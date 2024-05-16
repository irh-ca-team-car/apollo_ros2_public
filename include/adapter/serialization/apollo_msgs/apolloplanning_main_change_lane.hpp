#pragma once
#include "apollo_msgs/msg/apolloplanning_main_change_lane.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_target_lane.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_stop.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainChangeLane &msg) ;
    ApolloplanningMainChangeLane from_json_ApolloplanningMainChangeLane (nlohmann::json obj) ;
    template <>
    ApolloplanningMainChangeLane from_json<ApolloplanningMainChangeLane>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainChangeLane &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainChangeLane & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainChangeLane & dt);
}
