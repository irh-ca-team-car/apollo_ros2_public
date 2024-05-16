#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_trajectory_point_raw_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_path_point_raw_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_speed_point_raw_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningTrajectoryPointRawFeature &msg) ;
    ApolloplanningautotuningTrajectoryPointRawFeature from_json_ApolloplanningautotuningTrajectoryPointRawFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningTrajectoryPointRawFeature from_json<ApolloplanningautotuningTrajectoryPointRawFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningTrajectoryPointRawFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningTrajectoryPointRawFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningTrajectoryPointRawFeature & dt);
}
