#pragma once
#include "apollo_msgs/msg/apollohdmap_road.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_road_section.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRoad &msg) ;
    ApollohdmapRoad from_json_ApollohdmapRoad (nlohmann::json obj) ;
    template <>
    ApollohdmapRoad from_json<ApollohdmapRoad>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRoad &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRoad & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRoad & dt);
}
