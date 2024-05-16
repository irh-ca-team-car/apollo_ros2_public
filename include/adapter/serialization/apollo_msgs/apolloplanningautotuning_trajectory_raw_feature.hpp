#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_trajectory_raw_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_point_raw_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_st_raw_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningTrajectoryRawFeature &msg) ;
    ApolloplanningautotuningTrajectoryRawFeature from_json_ApolloplanningautotuningTrajectoryRawFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningTrajectoryRawFeature from_json<ApolloplanningautotuningTrajectoryRawFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningTrajectoryRawFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningTrajectoryRawFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningTrajectoryRawFeature & dt);
}
