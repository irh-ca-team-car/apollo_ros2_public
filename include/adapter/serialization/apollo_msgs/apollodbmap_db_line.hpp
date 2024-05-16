#pragma once
#include "apollo_msgs/msg/apollodbmap_db_line.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodbmap_db_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBLine &msg) ;
    ApollodbmapDBLine from_json_ApollodbmapDBLine (nlohmann::json obj) ;
    template <>
    ApollodbmapDBLine from_json<ApollodbmapDBLine>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBLine &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBLine & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBLine & dt);
}
