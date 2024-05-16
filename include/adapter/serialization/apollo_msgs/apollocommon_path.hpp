#pragma once
#include "apollo_msgs/msg/apollocommon_path.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_path_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPath &msg) ;
    ApollocommonPath from_json_ApollocommonPath (nlohmann::json obj) ;
    template <>
    ApollocommonPath from_json<ApollocommonPath>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPath &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonPath & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPath & dt);
}
