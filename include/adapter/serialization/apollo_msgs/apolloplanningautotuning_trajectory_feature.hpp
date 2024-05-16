#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_trajectory_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_pointwise_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningTrajectoryFeature &msg) ;
    ApolloplanningautotuningTrajectoryFeature from_json_ApolloplanningautotuningTrajectoryFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningTrajectoryFeature from_json<ApolloplanningautotuningTrajectoryFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningTrajectoryFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningTrajectoryFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningTrajectoryFeature & dt);
}
