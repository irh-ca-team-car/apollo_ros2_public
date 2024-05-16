#pragma once
#include "modules/common/proto/pnc_point.pb.h"
#include "apollo_msgs/msg/apolloplanningautotuning_path_point_raw_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_path_point_raw_feature.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningPathPointRawFeature PathPointRawFeature;
}
#include "apollo_msgs/msg/apolloplanningautotuning_object_decision_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_object_decision_feature.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningObjectDecisionFeature ObjectDecisionFeature;
}
#include "apollo_msgs/msg/apolloplanningautotuning_speed_point_raw_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_speed_point_raw_feature.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningSpeedPointRawFeature SpeedPointRawFeature;
}
#include "apollo_msgs/msg/apolloplanningautotuning_st_point_pair.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_st_point_pair.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningSTPointPair STPointPair;
}
#include "apollo_msgs/msg/apolloplanningautotuning_obstacle_st_data.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_st_data.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningObstacleSTData ObstacleSTData;
}
#include "apollo_msgs/msg/apolloplanningautotuning_obstacle_st_raw_data.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_st_raw_data.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningObstacleSTRawData ObstacleSTRawData;
}
#include "apollo_msgs/msg/apolloplanningautotuning_trajectory_point_raw_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_point_raw_feature.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningTrajectoryPointRawFeature TrajectoryPointRawFeature;
}
#include "apollo_msgs/msg/apolloplanningautotuning_trajectory_raw_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_raw_feature.hpp"
namespace apollo::planning::autotuning{
	typedef apollo_msgs::msg::ApolloplanningautotuningTrajectoryRawFeature TrajectoryRawFeature;
}