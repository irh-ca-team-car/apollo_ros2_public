#pragma once
#include "apollo_msgs/msg/apolloplanning_task_stats.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTaskStats &msg) ;
    ApolloplanningTaskStats from_json_ApolloplanningTaskStats (nlohmann::json obj) ;
    template <>
    ApolloplanningTaskStats from_json<ApolloplanningTaskStats>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTaskStats &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTaskStats & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTaskStats & dt);
}
