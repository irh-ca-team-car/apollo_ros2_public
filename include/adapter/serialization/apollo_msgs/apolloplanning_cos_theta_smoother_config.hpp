#pragma once
#include "apollo_msgs/msg/apolloplanning_cos_theta_smoother_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCosThetaSmootherConfig &msg) ;
    ApolloplanningCosThetaSmootherConfig from_json_ApolloplanningCosThetaSmootherConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningCosThetaSmootherConfig from_json<ApolloplanningCosThetaSmootherConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCosThetaSmootherConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCosThetaSmootherConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCosThetaSmootherConfig & dt);
}
