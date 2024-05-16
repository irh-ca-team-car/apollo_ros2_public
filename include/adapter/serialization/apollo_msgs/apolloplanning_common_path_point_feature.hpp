#pragma once
#include "apollo_msgs/msg/apolloplanning_common_path_point_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCommonPathPointFeature &msg) ;
    ApolloplanningCommonPathPointFeature from_json_ApolloplanningCommonPathPointFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningCommonPathPointFeature from_json<ApolloplanningCommonPathPointFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCommonPathPointFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCommonPathPointFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCommonPathPointFeature & dt);
}
