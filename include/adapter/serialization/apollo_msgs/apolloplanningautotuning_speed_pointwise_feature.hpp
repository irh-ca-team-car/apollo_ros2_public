#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_speed_pointwise_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningSpeedPointwiseFeature &msg) ;
    ApolloplanningautotuningSpeedPointwiseFeature from_json_ApolloplanningautotuningSpeedPointwiseFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningSpeedPointwiseFeature from_json<ApolloplanningautotuningSpeedPointwiseFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningSpeedPointwiseFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningSpeedPointwiseFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningSpeedPointwiseFeature & dt);
}
