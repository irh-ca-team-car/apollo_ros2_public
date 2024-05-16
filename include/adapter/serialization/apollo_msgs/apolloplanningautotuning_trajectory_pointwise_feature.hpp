#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_trajectory_pointwise_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_path_pointwise_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_speed_pointwise_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningTrajectoryPointwiseFeature &msg) ;
    ApolloplanningautotuningTrajectoryPointwiseFeature from_json_ApolloplanningautotuningTrajectoryPointwiseFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningTrajectoryPointwiseFeature from_json<ApolloplanningautotuningTrajectoryPointwiseFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningTrajectoryPointwiseFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningTrajectoryPointwiseFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningTrajectoryPointwiseFeature & dt);
}
