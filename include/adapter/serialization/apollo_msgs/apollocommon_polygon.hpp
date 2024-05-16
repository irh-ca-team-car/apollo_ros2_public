#pragma once
#include "apollo_msgs/msg/apollocommon_polygon.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPolygon &msg) ;
    ApollocommonPolygon from_json_ApollocommonPolygon (nlohmann::json obj) ;
    template <>
    ApollocommonPolygon from_json<ApollocommonPolygon>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPolygon &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonPolygon & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPolygon & dt);
}
