#pragma once
#include "apollo_msgs/msg/apolloplanning_discrete_points_smoother_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_discrete_points_smoother_config_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDiscretePointsSmootherConfig &msg) ;
    ApolloplanningDiscretePointsSmootherConfig from_json_ApolloplanningDiscretePointsSmootherConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningDiscretePointsSmootherConfig from_json<ApolloplanningDiscretePointsSmootherConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDiscretePointsSmootherConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDiscretePointsSmootherConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDiscretePointsSmootherConfig & dt);
}
