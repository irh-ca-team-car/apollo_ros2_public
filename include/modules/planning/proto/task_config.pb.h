#pragma once
#include "apollo_msgs/msg/apolloplanning_creep_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_creep_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningCreepDeciderConfig CreepDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_lane_change_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_lane_change_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningLaneChangeDeciderConfig LaneChangeDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_learning_model_inference_task_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_model_inference_task_config.hpp"
#include "apollo_msgs/msg/apolloplanning_learning_model_inference_trajectory_task_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_model_inference_trajectory_task_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningLearningModelInferenceTrajectoryTaskConfig LearningModelInferenceTrajectoryTaskConfig;
}
#include "apollo_msgs/msg/apolloplanning_navi_obstacle_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_navi_obstacle_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningNaviObstacleDeciderConfig NaviObstacleDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_navi_path_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_navi_path_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningNaviPathDeciderConfig NaviPathDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_move_dest_lane_config_table.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_move_dest_lane_config_table.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningMoveDestLaneConfigTable MoveDestLaneConfigTable;
}
#include "apollo_msgs/msg/apolloplanning_shift_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_shift_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningShiftConfig ShiftConfig;
}
#include "apollo_msgs/msg/apolloplanning_navi_speed_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_navi_speed_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningNaviSpeedDeciderConfig NaviSpeedDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_path_bounds_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_bounds_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPathBoundsDeciderConfig PathBoundsDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_path_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPathDeciderConfig PathDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_path_lane_borrow_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_lane_borrow_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPathLaneBorrowDeciderConfig PathLaneBorrowDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_path_reference_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_reference_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPathReferenceDeciderConfig PathReferenceDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_path_reuse_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_reuse_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPathReuseDeciderConfig PathReuseDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_piecewise_jerk_nonlinear_speed_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_nonlinear_speed_optimizer_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig PiecewiseJerkNonlinearSpeedOptimizerConfig;
}
#include "apollo_msgs/msg/apolloplanning_piecewise_jerk_path_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_path_optimizer_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPiecewiseJerkPathOptimizerConfig PiecewiseJerkPathOptimizerConfig;
}
#include "apollo_msgs/msg/apolloplanning_piecewise_jerk_path_weights.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_path_weights.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPiecewiseJerkPathWeights PiecewiseJerkPathWeights;
}
#include "apollo_msgs/msg/apolloplanning_piecewise_jerk_speed_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_speed_optimizer_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPiecewiseJerkSpeedOptimizerConfig PiecewiseJerkSpeedOptimizerConfig;
}
#include "apollo_msgs/msg/apolloplanning_rule_based_stop_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_rule_based_stop_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningRuleBasedStopDeciderConfig RuleBasedStopDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_speed_bounds_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_speed_bounds_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningSpeedBoundsDeciderConfig SpeedBoundsDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_speed_heuristic_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_speed_heuristic_optimizer_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningSpeedHeuristicOptimizerConfig SpeedHeuristicOptimizerConfig;
}
#include "apollo_msgs/msg/apolloplanning_dp_st_speed_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_dp_st_speed_optimizer_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningDpStSpeedOptimizerConfig DpStSpeedOptimizerConfig;
}
#include "apollo_msgs/msg/apolloplanning_st_bounds_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_st_bounds_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningSTBoundsDeciderConfig STBoundsDeciderConfig;
}
namespace apollo::planning::LearningModelInferenceTaskConfig{
	enum ModelType {
		CNN = 1,
		CNN_LSTM = 2
	};
}