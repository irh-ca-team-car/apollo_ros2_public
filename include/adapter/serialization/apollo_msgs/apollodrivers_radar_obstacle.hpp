#pragma once
#include "apollo_msgs/msg/apollodrivers_radar_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRadarObstacle &msg) ;
    ApollodriversRadarObstacle from_json_ApollodriversRadarObstacle (nlohmann::json obj) ;
    template <>
    ApollodriversRadarObstacle from_json<ApollodriversRadarObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRadarObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversRadarObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRadarObstacle & dt);
}
