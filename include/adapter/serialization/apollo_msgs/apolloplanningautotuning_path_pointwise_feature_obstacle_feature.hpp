#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_path_pointwise_feature_obstacle_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningPathPointwiseFeatureObstacleFeature &msg) ;
    ApolloplanningautotuningPathPointwiseFeatureObstacleFeature from_json_ApolloplanningautotuningPathPointwiseFeatureObstacleFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningPathPointwiseFeatureObstacleFeature from_json<ApolloplanningautotuningPathPointwiseFeatureObstacleFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningPathPointwiseFeatureObstacleFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningPathPointwiseFeatureObstacleFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningPathPointwiseFeatureObstacleFeature & dt);
}
