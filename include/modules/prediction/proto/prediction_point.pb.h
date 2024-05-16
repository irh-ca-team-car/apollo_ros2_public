#pragma once
#include "apollo_msgs/msg/apolloprediction_prediction_path_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_path_point.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionPredictionPathPoint PredictionPathPoint;
}
#include "apollo_msgs/msg/apolloprediction_prediction_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_trajectory_point.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionPredictionTrajectoryPoint PredictionTrajectoryPoint;
}