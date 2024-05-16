#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_obstacle_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningObstacleFeature &msg) ;
    ApolloplanningautotuningObstacleFeature from_json_ApolloplanningautotuningObstacleFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningObstacleFeature from_json<ApolloplanningautotuningObstacleFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningObstacleFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningObstacleFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningObstacleFeature & dt);
}
