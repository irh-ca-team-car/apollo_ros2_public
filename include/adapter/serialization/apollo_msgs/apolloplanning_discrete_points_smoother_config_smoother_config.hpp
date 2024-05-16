#pragma once
#include "apollo_msgs/msg/apolloplanning_discrete_points_smoother_config_smoother_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_cos_theta_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_fem_pos_deviation_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDiscretePointsSmootherConfigSmootherConfig &msg) ;
    ApolloplanningDiscretePointsSmootherConfigSmootherConfig from_json_ApolloplanningDiscretePointsSmootherConfigSmootherConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningDiscretePointsSmootherConfigSmootherConfig from_json<ApolloplanningDiscretePointsSmootherConfigSmootherConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDiscretePointsSmootherConfigSmootherConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDiscretePointsSmootherConfigSmootherConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDiscretePointsSmootherConfigSmootherConfig & dt);
}
