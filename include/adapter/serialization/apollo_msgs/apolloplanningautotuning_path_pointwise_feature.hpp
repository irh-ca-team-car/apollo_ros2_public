#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_path_pointwise_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_bound_related_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningPathPointwiseFeature &msg) ;
    ApolloplanningautotuningPathPointwiseFeature from_json_ApolloplanningautotuningPathPointwiseFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningPathPointwiseFeature from_json<ApolloplanningautotuningPathPointwiseFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningPathPointwiseFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningPathPointwiseFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningPathPointwiseFeature & dt);
}
