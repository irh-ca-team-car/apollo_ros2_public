#pragma once
#include "apollo_msgs/msg/apolloperception_impending_collision_edge.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionImpendingCollisionEdge &msg) ;
    ApolloperceptionImpendingCollisionEdge from_json_ApolloperceptionImpendingCollisionEdge (nlohmann::json obj) ;
    template <>
    ApolloperceptionImpendingCollisionEdge from_json<ApolloperceptionImpendingCollisionEdge>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionImpendingCollisionEdge &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionImpendingCollisionEdge & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionImpendingCollisionEdge & dt);
}
