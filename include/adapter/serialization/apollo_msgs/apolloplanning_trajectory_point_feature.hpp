#pragma once
#include "apollo_msgs/msg/apolloplanning_trajectory_point_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_common_trajectory_point_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrajectoryPointFeature &msg) ;
    ApolloplanningTrajectoryPointFeature from_json_ApolloplanningTrajectoryPointFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningTrajectoryPointFeature from_json<ApolloplanningTrajectoryPointFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrajectoryPointFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrajectoryPointFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrajectoryPointFeature & dt);
}
