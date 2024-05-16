#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_bound_related_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningBoundRelatedFeature &msg) ;
    ApolloplanningautotuningBoundRelatedFeature from_json_ApolloplanningautotuningBoundRelatedFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningBoundRelatedFeature from_json<ApolloplanningautotuningBoundRelatedFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningBoundRelatedFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningBoundRelatedFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningBoundRelatedFeature & dt);
}
