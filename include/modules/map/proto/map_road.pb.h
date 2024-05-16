#pragma once
#include "modules/map/proto/map_geometry.pb.h"
#include "modules/map/proto/map_id.pb.h"
#include "apollo_msgs/msg/apollohdmap_boundary_edge.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_boundary_edge.hpp"
#include "apollo_msgs/msg/apollohdmap_boundary_polygon.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_boundary_polygon.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapBoundaryPolygon BoundaryPolygon;
}
#include "apollo_msgs/msg/apollohdmap_road_boundary.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_road_boundary.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapRoadBoundary RoadBoundary;
}
#include "apollo_msgs/msg/apollohdmap_road_roi_boundary.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_road_roi_boundary.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapRoadROIBoundary RoadROIBoundary;
}
#include "apollo_msgs/msg/apollohdmap_road_section.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_road_section.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapRoadSection RoadSection;
}
#include "apollo_msgs/msg/apollohdmap_road.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_road.hpp"
namespace apollo::hdmap::BoundaryEdge{
	enum Type {
		UNKNOWN = 0,
		NORMAL = 1,
		LEFT_BOUNDARY = 2,
		RIGHT_BOUNDARY = 3
	};
}
namespace apollo::hdmap::Road{
	enum Type {
		UNKNOWN = 0,
		HIGHWAY = 1,
		CITY_ROAD = 2,
		PARK = 3
	};
}