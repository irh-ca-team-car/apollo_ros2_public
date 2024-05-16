#pragma once
#include "apollo_msgs/msg/apollohdmap_road_section.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_road_boundary.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRoadSection &msg) ;
    ApollohdmapRoadSection from_json_ApollohdmapRoadSection (nlohmann::json obj) ;
    template <>
    ApollohdmapRoadSection from_json<ApollohdmapRoadSection>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRoadSection &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRoadSection & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRoadSection & dt);
}
