#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_bound_related_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_bound_related_feature.hpp"
#include "apollo_msgs/msg/apolloplanningautotuning_path_pointwise_feature_obstacle_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_path_pointwise_feature_obstacle_feature.hpp"
namespace apollo::planning::autotuning::PathPointwiseFeature{
	typedef apollo_msgs::msg::ApolloplanningautotuningPathPointwiseFeatureObstacleFeature ObstacleFeature;
}
#include "apollo_msgs/msg/apolloplanningautotuning_path_pointwise_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_path_pointwise_feature.hpp"
#include "apollo_msgs/msg/apolloplanningautotuning_obstacle_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_feature.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningObstacleFeature ObstacleFeature;
}
#include "apollo_msgs/msg/apolloplanningautotuning_speed_pointwise_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_speed_pointwise_feature.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningSpeedPointwiseFeature SpeedPointwiseFeature;
}
#include "apollo_msgs/msg/apolloplanningautotuning_trajectory_pointwise_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_pointwise_feature.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningTrajectoryPointwiseFeature TrajectoryPointwiseFeature;
}
#include "apollo_msgs/msg/apolloplanningautotuning_trajectory_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_feature.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningTrajectoryFeature TrajectoryFeature;
}
namespace apollo::planning::autotuning::BoundRelatedFeature{
	enum CrossableLevel {
		CROSS_FREE = 0,
		CROSS_ABLE = 1,
		CROSS_FORBIDDEN = 2
	};
}