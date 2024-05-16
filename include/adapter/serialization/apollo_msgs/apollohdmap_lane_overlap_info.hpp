#pragma once
#include "apollo_msgs/msg/apollohdmap_lane_overlap_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLaneOverlapInfo &msg) ;
    ApollohdmapLaneOverlapInfo from_json_ApollohdmapLaneOverlapInfo (nlohmann::json obj) ;
    template <>
    ApollohdmapLaneOverlapInfo from_json<ApollohdmapLaneOverlapInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLaneOverlapInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLaneOverlapInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLaneOverlapInfo & dt);
}
