#pragma once
#include "apollo_msgs/msg/apollohdmap_road_roi_boundary.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_road_boundary.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRoadROIBoundary &msg) ;
    ApollohdmapRoadROIBoundary from_json_ApollohdmapRoadROIBoundary (nlohmann::json obj) ;
    template <>
    ApollohdmapRoadROIBoundary from_json<ApollohdmapRoadROIBoundary>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRoadROIBoundary &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRoadROIBoundary & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRoadROIBoundary & dt);
}
