#pragma once
#include "apollo_msgs/msg/apollodbmap_db_map.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodbmap_db_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBMap &msg) ;
    ApollodbmapDBMap from_json_ApollodbmapDBMap (nlohmann::json obj) ;
    template <>
    ApollodbmapDBMap from_json<ApollodbmapDBMap>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBMap &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBMap & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBMap & dt);
}
