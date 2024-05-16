#pragma once
#include "apollo_msgs/msg/apollocontrol_mrac_adaptive_gain.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolMracAdaptiveGain &msg) ;
    ApollocontrolMracAdaptiveGain from_json_ApollocontrolMracAdaptiveGain (nlohmann::json obj) ;
    template <>
    ApollocontrolMracAdaptiveGain from_json<ApollocontrolMracAdaptiveGain>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolMracAdaptiveGain &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolMracAdaptiveGain & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolMracAdaptiveGain & dt);
}
