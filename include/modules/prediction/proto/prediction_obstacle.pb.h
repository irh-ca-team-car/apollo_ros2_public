#pragma once
#include "modules/common/proto/error_code.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/prediction/proto/scenario.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/prediction/proto/feature.pb.h"
#include "apollo_msgs/msg/apolloprediction_obstacle_intent.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_intent.hpp"
#include "apollo_msgs/msg/apolloprediction_intent.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_intent.hpp"
#include "apollo_msgs/msg/apolloprediction_prediction_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_obstacle.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionPredictionObstacle PredictionObstacle;
}
#include "apollo_msgs/msg/apolloprediction_prediction_obstacles.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_obstacles.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionPredictionObstacles PredictionObstacles;
}
namespace apollo::prediction::ObstacleIntent{
	enum Type {
		UNKNOWN = 0,
		STOP = 1,
		STATIONARY = 2,
		MOVING = 3,
		CHANGE_LANE = 4,
		LOW_ACCELERATION = 5,
		HIGH_ACCELERATION = 6,
		LOW_DECELERATION = 7,
		HIGH_DECELERATION = 8
	};
}
namespace apollo::prediction::Intent{
	enum Type {
		UNKNOWN = 0,
		STOP = 1,
		CRUISE = 2,
		CHANGE_LANE = 3
	};
}