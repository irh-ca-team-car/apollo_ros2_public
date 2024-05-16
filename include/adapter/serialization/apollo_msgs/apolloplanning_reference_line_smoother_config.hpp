#pragma once
#include "apollo_msgs/msg/apolloplanning_reference_line_smoother_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_reference_line_smoother_config_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningReferenceLineSmootherConfig &msg) ;
    ApolloplanningReferenceLineSmootherConfig from_json_ApolloplanningReferenceLineSmootherConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningReferenceLineSmootherConfig from_json<ApolloplanningReferenceLineSmootherConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningReferenceLineSmootherConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningReferenceLineSmootherConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningReferenceLineSmootherConfig & dt);
}
