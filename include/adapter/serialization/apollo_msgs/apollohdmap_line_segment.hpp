#pragma once
#include "apollo_msgs/msg/apollohdmap_line_segment.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLineSegment &msg) ;
    ApollohdmapLineSegment from_json_ApollohdmapLineSegment (nlohmann::json obj) ;
    template <>
    ApollohdmapLineSegment from_json<ApollohdmapLineSegment>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLineSegment &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLineSegment & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLineSegment & dt);
}
