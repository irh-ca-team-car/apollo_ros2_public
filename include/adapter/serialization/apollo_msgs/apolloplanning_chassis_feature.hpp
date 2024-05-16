#pragma once
#include "apollo_msgs/msg/apolloplanning_chassis_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningChassisFeature &msg) ;
    ApolloplanningChassisFeature from_json_ApolloplanningChassisFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningChassisFeature from_json<ApolloplanningChassisFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningChassisFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningChassisFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningChassisFeature & dt);
}
