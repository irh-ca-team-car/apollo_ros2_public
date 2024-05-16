#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_object_decision_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningObjectDecisionFeature &msg) ;
    ApolloplanningautotuningObjectDecisionFeature from_json_ApolloplanningautotuningObjectDecisionFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningObjectDecisionFeature from_json<ApolloplanningautotuningObjectDecisionFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningObjectDecisionFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningObjectDecisionFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningObjectDecisionFeature & dt);
}
