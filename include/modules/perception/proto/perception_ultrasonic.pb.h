#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apolloperception_impending_collision_edge.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_impending_collision_edge.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionImpendingCollisionEdge ImpendingCollisionEdge;
}
#include "apollo_msgs/msg/apolloperception_impending_collision_edges.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_impending_collision_edges.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionImpendingCollisionEdges ImpendingCollisionEdges;
}