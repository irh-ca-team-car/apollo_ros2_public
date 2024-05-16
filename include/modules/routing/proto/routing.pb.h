#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/error_code.pb.h"
#include "modules/map/proto/map_parking_space.pb.h"
#include "apollo_msgs/msg/apollorouting_lane_waypoint.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_lane_waypoint.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingLaneWaypoint LaneWaypoint;
}
#include "apollo_msgs/msg/apollorouting_lane_segment.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_lane_segment.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingLaneSegment LaneSegment;
}
#include "apollo_msgs/msg/apollorouting_parking_info.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_parking_info.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingParkingInfo ParkingInfo;
}
#include "apollo_msgs/msg/apollorouting_routing_request.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_routing_request.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingRoutingRequest RoutingRequest;
}
#include "apollo_msgs/msg/apollorouting_measurement.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_measurement.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingMeasurement Measurement;
}
#include "apollo_msgs/msg/apollorouting_passage.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_passage.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingPassage Passage;
}
#include "apollo_msgs/msg/apollorouting_road_segment.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_road_segment.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingRoadSegment RoadSegment;
}
#include "apollo_msgs/msg/apollorouting_routing_response.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_routing_response.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingRoutingResponse RoutingResponse;
}
namespace apollo::routing{
	enum ChangeLaneType {
		FORWARD = 0,
		LEFT = 1,
		RIGHT = 2
	};
}