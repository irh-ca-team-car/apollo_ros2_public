#pragma once
#include "apollo_msgs/msg/apolloplanning_reference_line_smoother_config_smoother_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_qp_spline_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_spiral_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_discrete_points_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningReferenceLineSmootherConfigSmootherConfig &msg) ;
    ApolloplanningReferenceLineSmootherConfigSmootherConfig from_json_ApolloplanningReferenceLineSmootherConfigSmootherConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningReferenceLineSmootherConfigSmootherConfig from_json<ApolloplanningReferenceLineSmootherConfigSmootherConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningReferenceLineSmootherConfigSmootherConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningReferenceLineSmootherConfigSmootherConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningReferenceLineSmootherConfigSmootherConfig & dt);
}
