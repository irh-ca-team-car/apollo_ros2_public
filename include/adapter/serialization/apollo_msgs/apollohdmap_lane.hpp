#pragma once
#include "apollo_msgs/msg/apollohdmap_lane.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_lane_boundary.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_lane_sample_association.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLane &msg) ;
    ApollohdmapLane from_json_ApollohdmapLane (nlohmann::json obj) ;
    template <>
    ApollohdmapLane from_json<ApollohdmapLane>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLane &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLane & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLane & dt);
}
