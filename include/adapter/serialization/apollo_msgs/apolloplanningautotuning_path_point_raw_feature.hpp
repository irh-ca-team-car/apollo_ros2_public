#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_path_point_raw_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_path_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_frenet_frame_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningPathPointRawFeature &msg) ;
    ApolloplanningautotuningPathPointRawFeature from_json_ApolloplanningautotuningPathPointRawFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningPathPointRawFeature from_json<ApolloplanningautotuningPathPointRawFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningPathPointRawFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningPathPointRawFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningPathPointRawFeature & dt);
}
