#pragma once
#include "apollo_msgs/msg/apollohdmap_polygon.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapPolygon &msg) ;
    ApollohdmapPolygon from_json_ApollohdmapPolygon (nlohmann::json obj) ;
    template <>
    ApollohdmapPolygon from_json<ApollohdmapPolygon>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapPolygon &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapPolygon & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapPolygon & dt);
}
