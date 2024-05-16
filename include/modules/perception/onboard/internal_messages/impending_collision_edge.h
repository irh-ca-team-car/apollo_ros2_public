#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/impending_collision_edge.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::ImpendingCollisionEdge;
    nlohmann::json to_json(const ImpendingCollisionEdge &msg);
    ImpendingCollisionEdge from_json_ImpendingCollisionEdge(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ImpendingCollisionEdge &dt);
    std::ostream &operator<<(std::ostream &os, const ImpendingCollisionEdge &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const ImpendingCollisionEdge &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::ImpendingCollisionEdges;
    nlohmann::json to_json(const ImpendingCollisionEdges &msg);
    ImpendingCollisionEdges from_json_ImpendingCollisionEdges(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ImpendingCollisionEdges &dt);
    std::ostream &operator<<(std::ostream &os, const ImpendingCollisionEdges &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const ImpendingCollisionEdges &dt);
}
