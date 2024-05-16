#pragma once
#include "apollo_msgs/msg/apollohdmap_region_overlap_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRegionOverlapInfo &msg) ;
    ApollohdmapRegionOverlapInfo from_json_ApollohdmapRegionOverlapInfo (nlohmann::json obj) ;
    template <>
    ApollohdmapRegionOverlapInfo from_json<ApollohdmapRegionOverlapInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRegionOverlapInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRegionOverlapInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRegionOverlapInfo & dt);
}
