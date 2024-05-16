#pragma once
#include "apollo_msgs/msg/apollohdmap_lane_boundary.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_lane_boundary_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLaneBoundary &msg) ;
    ApollohdmapLaneBoundary from_json_ApollohdmapLaneBoundary (nlohmann::json obj) ;
    template <>
    ApollohdmapLaneBoundary from_json<ApollohdmapLaneBoundary>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLaneBoundary &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLaneBoundary & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLaneBoundary & dt);
}
