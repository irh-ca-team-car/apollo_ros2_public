#pragma once
#include "apollo_msgs/msg/apolloplanning_perception_obstacle_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPerceptionObstacleFeature &msg) ;
    ApolloplanningPerceptionObstacleFeature from_json_ApolloplanningPerceptionObstacleFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningPerceptionObstacleFeature from_json<ApolloplanningPerceptionObstacleFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPerceptionObstacleFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPerceptionObstacleFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPerceptionObstacleFeature & dt);
}
