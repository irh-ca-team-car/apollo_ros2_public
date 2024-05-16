#pragma once
#include "apollo_msgs/msg/apollocommon_path_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPathPoint &msg) ;
    ApollocommonPathPoint from_json_ApollocommonPathPoint (nlohmann::json obj) ;
    template <>
    ApollocommonPathPoint from_json<ApollocommonPathPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPathPoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonPathPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPathPoint & dt);
}
