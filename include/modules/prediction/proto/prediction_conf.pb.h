#pragma once
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/prediction/proto/feature.pb.h"
#include "apollo_msgs/msg/apolloprediction_obstacle_conf.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_conf.hpp"
#include "apollo_msgs/msg/apolloprediction_topic_conf.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_topic_conf.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionTopicConf TopicConf;
}
#include "apollo_msgs/msg/apolloprediction_prediction_conf.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_conf.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionPredictionConf PredictionConf;
}
namespace apollo::prediction::ObstacleConf{
	enum ObstacleStatus {
		ON_LANE = 0,
		OFF_LANE = 1,
		STATIONARY = 3,
		MOVING = 4,
		IN_JUNCTION = 5
	};
}
namespace apollo::prediction::ObstacleConf{
	enum EvaluatorType {
		MLP_EVALUATOR = 0,
		RNN_EVALUATOR = 1 ,
		COST_EVALUATOR = 2,  // navi mode can only support this evaluator
		CRUISE_MLP_EVALUATOR = 3,
		JUNCTION_MLP_EVALUATOR = 4,
		CYCLIST_KEEP_LANE_EVALUATOR = 5,
		LANE_SCANNING_EVALUATOR = 6,
		PEDESTRIAN_INTERACTION_EVALUATOR = 7,
		JUNCTION_MAP_EVALUATOR = 8,
		LANE_AGGREGATING_EVALUATOR = 9,
		SEMANTIC_LSTM_EVALUATOR = 10
	};
}
namespace apollo::prediction::ObstacleConf{
	enum PredictorType {
		LANE_SEQUENCE_PREDICTOR = 0,
		FREE_MOVE_PREDICTOR = 1,
		REGIONAL_PREDICTOR = 2 ,
		MOVE_SEQUENCE_PREDICTOR = 3,
		EMPTY_PREDICTOR = 4,
		SINGLE_LANE_PREDICTOR = 5,
		JUNCTION_PREDICTOR = 6,
		EXTRAPOLATION_PREDICTOR = 7,
		INTERACTION_PREDICTOR = 8
	};
}