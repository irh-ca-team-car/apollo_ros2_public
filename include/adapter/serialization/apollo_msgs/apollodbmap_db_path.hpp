#pragma once
#include "apollo_msgs/msg/apollodbmap_db_path.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodbmap_db_line.hpp"
#include "adapter/serialization/apollo_msgs/apollodbmap_db_neighbour_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBPath &msg) ;
    ApollodbmapDBPath from_json_ApollodbmapDBPath (nlohmann::json obj) ;
    template <>
    ApollodbmapDBPath from_json<ApollodbmapDBPath>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBPath &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBPath & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBPath & dt);
}
