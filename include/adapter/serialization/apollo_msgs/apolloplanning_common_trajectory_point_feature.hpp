#pragma once
#include "apollo_msgs/msg/apolloplanning_common_trajectory_point_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_common_path_point_feature.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_gaussian_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCommonTrajectoryPointFeature &msg) ;
    ApolloplanningCommonTrajectoryPointFeature from_json_ApolloplanningCommonTrajectoryPointFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningCommonTrajectoryPointFeature from_json<ApolloplanningCommonTrajectoryPointFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCommonTrajectoryPointFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCommonTrajectoryPointFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCommonTrajectoryPointFeature & dt);
}
