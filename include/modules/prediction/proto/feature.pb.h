#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/map/proto/map_lane.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/prediction/proto/lane_graph.pb.h"
#include "modules/prediction/proto/prediction_point.pb.h"
#include "apollo_msgs/msg/apolloprediction_lane.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionLane Lane;
}
#include "apollo_msgs/msg/apolloprediction_lane_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lane_feature.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionLaneFeature LaneFeature;
}
#include "apollo_msgs/msg/apolloprediction_junction_exit.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_junction_exit.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionJunctionExit JunctionExit;
}
#include "apollo_msgs/msg/apolloprediction_junction_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_junction_feature.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionJunctionFeature JunctionFeature;
}
#include "apollo_msgs/msg/apolloprediction_obstacle_priority.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_priority.hpp"
#include "apollo_msgs/msg/apolloprediction_trajectory.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_trajectory.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionTrajectory Trajectory;
}
#include "apollo_msgs/msg/apolloprediction_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_feature.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionFeature Feature;
}
#include "apollo_msgs/msg/apolloprediction_obstacle_history.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_history.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionObstacleHistory ObstacleHistory;
}
#include "apollo_msgs/msg/apolloprediction_frame_env.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_frame_env.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionFrameEnv FrameEnv;
}
namespace apollo::prediction::ObstaclePriority{
	enum Priority {
		CAUTION = 1,
		NORMAL = 2,
		IGNORE = 3
	};
}