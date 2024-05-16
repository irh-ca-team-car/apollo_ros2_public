#pragma once
#include "apollo_msgs/msg/apolloplanning_reference_line_end_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningReferenceLineEndConfig &msg) ;
    ApolloplanningReferenceLineEndConfig from_json_ApolloplanningReferenceLineEndConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningReferenceLineEndConfig from_json<ApolloplanningReferenceLineEndConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningReferenceLineEndConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningReferenceLineEndConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningReferenceLineEndConfig & dt);
}
