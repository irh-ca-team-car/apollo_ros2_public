#pragma once
#include "apollo_msgs/msg/apollohdmap_clear_area.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapClearArea &msg) ;
    ApollohdmapClearArea from_json_ApollohdmapClearArea (nlohmann::json obj) ;
    template <>
    ApollohdmapClearArea from_json<ApollohdmapClearArea>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapClearArea &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapClearArea & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapClearArea & dt);
}
