#pragma once
#include "apollo_msgs/msg/apolloperception_impending_collision_edges.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_impending_collision_edge.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionImpendingCollisionEdges &msg) ;
    ApolloperceptionImpendingCollisionEdges from_json_ApolloperceptionImpendingCollisionEdges (nlohmann::json obj) ;
    template <>
    ApolloperceptionImpendingCollisionEdges from_json<ApolloperceptionImpendingCollisionEdges>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionImpendingCollisionEdges &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionImpendingCollisionEdges & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionImpendingCollisionEdges & dt);
}
