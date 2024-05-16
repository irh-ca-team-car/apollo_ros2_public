#pragma once
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/map/proto/map_lane.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/prediction/proto/feature.pb.h"
#include "modules/prediction/proto/prediction_obstacle.pb.h"
#include "modules/perception/proto/traffic_light_detection.pb.h"
#include "modules/routing/proto/routing.pb.h"
#include "apollo_msgs/msg/apolloplanning_overlap_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_overlap_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningOverlapFeature OverlapFeature;
}
#include "apollo_msgs/msg/apolloplanning_planning_tag.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planning_tag.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPlanningTag PlanningTag;
}
#include "apollo_msgs/msg/apolloplanning_chassis_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_chassis_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningChassisFeature ChassisFeature;
}
#include "apollo_msgs/msg/apolloplanning_localization_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_localization_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningLocalizationFeature LocalizationFeature;
}
#include "apollo_msgs/msg/apolloplanning_common_path_point_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_common_path_point_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningCommonPathPointFeature CommonPathPointFeature;
}
#include "apollo_msgs/msg/apolloplanning_common_trajectory_point_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_common_trajectory_point_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningCommonTrajectoryPointFeature CommonTrajectoryPointFeature;
}
#include "apollo_msgs/msg/apolloplanning_trajectory_point_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_trajectory_point_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTrajectoryPointFeature TrajectoryPointFeature;
}
#include "apollo_msgs/msg/apolloplanning_perception_obstacle_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_perception_obstacle_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPerceptionObstacleFeature PerceptionObstacleFeature;
}
#include "apollo_msgs/msg/apolloplanning_obstacle_trajectory_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_obstacle_trajectory_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningObstacleTrajectoryFeature ObstacleTrajectoryFeature;
}
#include "apollo_msgs/msg/apolloplanning_prediction_trajectory_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_prediction_trajectory_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPredictionTrajectoryFeature PredictionTrajectoryFeature;
}
#include "apollo_msgs/msg/apolloplanning_prediction_obstacle_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_prediction_obstacle_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPredictionObstacleFeature PredictionObstacleFeature;
}
#include "apollo_msgs/msg/apolloplanning_obstacle_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_obstacle_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningObstacleFeature ObstacleFeature;
}
#include "apollo_msgs/msg/apolloplanning_routing_response_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_routing_response_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningRoutingResponseFeature RoutingResponseFeature;
}
#include "apollo_msgs/msg/apolloplanning_routing_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_routing_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningRoutingFeature RoutingFeature;
}
#include "apollo_msgs/msg/apolloplanning_traffic_light_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTrafficLightFeature TrafficLightFeature;
}
#include "apollo_msgs/msg/apolloplanning_traffic_light_detection_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_detection_feature.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTrafficLightDetectionFeature TrafficLightDetectionFeature;
}
#include "apollo_msgs/msg/apolloplanning_adc_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_adc_trajectory_point.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningADCTrajectoryPoint ADCTrajectoryPoint;
}
#include "apollo_msgs/msg/apolloplanning_learning_output.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_output.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningLearningOutput LearningOutput;
}
#include "apollo_msgs/msg/apolloplanning_learning_data_frame.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_data_frame.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningLearningDataFrame LearningDataFrame;
}
#include "apollo_msgs/msg/apolloplanning_learning_data.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_data.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningLearningData LearningData;
}
#include "apollo_msgs/msg/apolloplanning_planning_learning_data.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planning_learning_data.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPlanningLearningData PlanningLearningData;
}