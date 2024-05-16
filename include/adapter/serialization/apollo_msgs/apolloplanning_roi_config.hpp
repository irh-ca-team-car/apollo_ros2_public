#pragma once
#include "apollo_msgs/msg/apolloplanning_roi_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningROIConfig &msg) ;
    ApolloplanningROIConfig from_json_ApolloplanningROIConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningROIConfig from_json<ApolloplanningROIConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningROIConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningROIConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningROIConfig & dt);
}
