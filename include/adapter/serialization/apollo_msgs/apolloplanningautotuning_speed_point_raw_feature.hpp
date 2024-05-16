#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_speed_point_raw_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_object_decision_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningSpeedPointRawFeature &msg) ;
    ApolloplanningautotuningSpeedPointRawFeature from_json_ApolloplanningautotuningSpeedPointRawFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningSpeedPointRawFeature from_json<ApolloplanningautotuningSpeedPointRawFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningSpeedPointRawFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningSpeedPointRawFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningSpeedPointRawFeature & dt);
}
