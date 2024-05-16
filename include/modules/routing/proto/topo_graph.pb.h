#pragma once
#include "modules/map/proto/map_geometry.pb.h"
#include "apollo_msgs/msg/apollorouting_curve_point.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_curve_point.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingCurvePoint CurvePoint;
}
#include "apollo_msgs/msg/apollorouting_curve_range.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_curve_range.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingCurveRange CurveRange;
}
#include "apollo_msgs/msg/apollorouting_node.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_node.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingNode Node;
}
#include "apollo_msgs/msg/apollorouting_edge.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_edge.hpp"
#include "apollo_msgs/msg/apollorouting_graph.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_graph.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingGraph Graph;
}
namespace apollo::routing::Edge{
	enum DirectionType {
		FORWARD = 0,
		LEFT = 1,
		RIGHT = 2
	};
}