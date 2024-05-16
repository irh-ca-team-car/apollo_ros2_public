#pragma once
#include "apollo_msgs/msg/apollodbmap_db_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBPoint &msg) ;
    ApollodbmapDBPoint from_json_ApollodbmapDBPoint (nlohmann::json obj) ;
    template <>
    ApollodbmapDBPoint from_json<ApollodbmapDBPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBPoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBPoint & dt);
}
