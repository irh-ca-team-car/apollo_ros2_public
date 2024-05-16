#pragma once
#include "apollo_msgs/msg/apolloplanning_qp_spline_smoother_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningQpSplineSmootherConfig &msg) ;
    ApolloplanningQpSplineSmootherConfig from_json_ApolloplanningQpSplineSmootherConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningQpSplineSmootherConfig from_json<ApolloplanningQpSplineSmootherConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningQpSplineSmootherConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningQpSplineSmootherConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningQpSplineSmootherConfig & dt);
}
