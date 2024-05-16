#pragma once
#include "apollo_msgs/msg/apolloplanning_path_reference_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathReferenceDeciderConfig &msg) ;
    ApolloplanningPathReferenceDeciderConfig from_json_ApolloplanningPathReferenceDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPathReferenceDeciderConfig from_json<ApolloplanningPathReferenceDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathReferenceDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathReferenceDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathReferenceDeciderConfig & dt);
}
