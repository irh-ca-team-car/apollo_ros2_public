#pragma once
#include "modules/map/proto/map_id.pb.h"
#include "modules/map/proto/map_geometry.pb.h"
#include "apollo_msgs/msg/apollohdmap_lane_boundary_type.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_lane_boundary_type.hpp"
#include "apollo_msgs/msg/apollohdmap_lane_boundary.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_lane_boundary.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapLaneBoundary LaneBoundary;
}
#include "apollo_msgs/msg/apollohdmap_lane_sample_association.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_lane_sample_association.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapLaneSampleAssociation LaneSampleAssociation;
}
#include "apollo_msgs/msg/apollohdmap_lane.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_lane.hpp"
namespace apollo::hdmap::LaneBoundaryType{
	enum Type {
		UNKNOWN = 0,
		DOTTED_YELLOW = 1,
		DOTTED_WHITE = 2,
		SOLID_YELLOW = 3,
		SOLID_WHITE = 4,
		DOUBLE_YELLOW = 5,
		CURB = 6
	};
}
namespace apollo::hdmap::Lane{
	enum LaneType {
		NONE = 1,
		CITY_DRIVING = 2,
		BIKING = 3,
		SIDEWALK = 4,
		PARKING = 5,
		SHOULDER = 6
	};
}
namespace apollo::hdmap::Lane{
	enum LaneTurn {
		NO_TURN = 1,
		LEFT_TURN = 2,
		RIGHT_TURN = 3,
		U_TURN = 4
	};
}
namespace apollo::hdmap::Lane{
	enum LaneDirection {
		FORWARD = 1,
		BACKWARD = 2,
		BIDIRECTION = 3
	};
}

#include "modules/map/proto/map_lane_name.pb.h"