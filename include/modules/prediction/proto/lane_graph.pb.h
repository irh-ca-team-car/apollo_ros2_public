#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/map/proto/map_lane.pb.h"
#include "apollo_msgs/msg/apolloprediction_lane_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_point.hpp"
#include "apollo_msgs/msg/apolloprediction_lane_segment.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_segment.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionLaneSegment LaneSegment;
}
#include "apollo_msgs/msg/apolloprediction_nearby_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_nearby_obstacle.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionNearbyObstacle NearbyObstacle;
}
#include "apollo_msgs/msg/apolloprediction_stop_sign.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_stop_sign.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionStopSign StopSign;
}
#include "apollo_msgs/msg/apolloprediction_lane_sequence_features.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_sequence_features.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionLaneSequenceFeatures LaneSequenceFeatures;
}
#include "apollo_msgs/msg/apolloprediction_lane_sequence.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_sequence.hpp"
#include "apollo_msgs/msg/apolloprediction_lane_graph.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_graph.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionLaneGraph LaneGraph;
}
#include "apollo_msgs/msg/apolloprediction_lane_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_obstacle.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionLaneObstacle LaneObstacle;
}
namespace apollo::prediction::LanePoint{
	enum ScenarioType {
		URBAN_ROAD = 0,
		JUNCTION = 1,
		HIGHWAY = 2
	};
}
namespace apollo::prediction::LaneSequence{
	enum BehaviorType {
		NOT_GOTO_LANE = 1,
		CONSTANT_SPEED = 2,
		SMALL_ACCELERATION = 3,
		LARGE_ACCELERATION = 4,
		SMALL_DECELERATION = 5,
		LARGE_DECELERATION = 6
	};
}