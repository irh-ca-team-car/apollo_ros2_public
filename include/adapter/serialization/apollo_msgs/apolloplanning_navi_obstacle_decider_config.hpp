#pragma once
#include "apollo_msgs/msg/apolloplanning_navi_obstacle_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningNaviObstacleDeciderConfig &msg) ;
    ApolloplanningNaviObstacleDeciderConfig from_json_ApolloplanningNaviObstacleDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningNaviObstacleDeciderConfig from_json<ApolloplanningNaviObstacleDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningNaviObstacleDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningNaviObstacleDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningNaviObstacleDeciderConfig & dt);
}
