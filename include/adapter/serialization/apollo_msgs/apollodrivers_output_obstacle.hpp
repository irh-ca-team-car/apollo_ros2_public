#pragma once
#include "apollo_msgs/msg/apollodrivers_output_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversOutputObstacle &msg) ;
    ApollodriversOutputObstacle from_json_ApollodriversOutputObstacle (nlohmann::json obj) ;
    template <>
    ApollodriversOutputObstacle from_json<ApollodriversOutputObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversOutputObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversOutputObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversOutputObstacle & dt);
}
