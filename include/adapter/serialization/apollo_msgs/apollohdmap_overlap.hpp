#pragma once
#include "apollo_msgs/msg/apollohdmap_overlap.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_object_overlap_info.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_region_overlap_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapOverlap &msg) ;
    ApollohdmapOverlap from_json_ApollohdmapOverlap (nlohmann::json obj) ;
    template <>
    ApollohdmapOverlap from_json<ApollohdmapOverlap>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapOverlap &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapOverlap & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapOverlap & dt);
}
