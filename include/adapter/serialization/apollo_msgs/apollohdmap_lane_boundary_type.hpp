#pragma once
#include "apollo_msgs/msg/apollohdmap_lane_boundary_type.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLaneBoundaryType &msg) ;
    ApollohdmapLaneBoundaryType from_json_ApollohdmapLaneBoundaryType (nlohmann::json obj) ;
    template <>
    ApollohdmapLaneBoundaryType from_json<ApollohdmapLaneBoundaryType>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLaneBoundaryType &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLaneBoundaryType & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLaneBoundaryType & dt);
}
