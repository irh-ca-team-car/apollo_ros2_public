#pragma once
#include "modules/planning/proto/planner_open_space_config.pb.h"
#include "apollo_msgs/msg/apolloplanning_open_space_fall_back_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_fall_back_decider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningOpenSpaceFallBackDeciderConfig OpenSpaceFallBackDeciderConfig;
}
#include "apollo_msgs/msg/apolloplanning_open_space_pre_stop_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_pre_stop_decider_config.hpp"
#include "apollo_msgs/msg/apolloplanning_open_space_roi_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_roi_decider_config.hpp"
#include "apollo_msgs/msg/apolloplanning_open_space_trajectory_partition_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_trajectory_partition_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningOpenSpaceTrajectoryPartitionConfig OpenSpaceTrajectoryPartitionConfig;
}
#include "apollo_msgs/msg/apolloplanning_open_space_trajectory_provider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_trajectory_provider_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningOpenSpaceTrajectoryProviderConfig OpenSpaceTrajectoryProviderConfig;
}
#include "apollo_msgs/msg/apolloplanning_open_space_trajectory_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_trajectory_optimizer_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningOpenSpaceTrajectoryOptimizerConfig OpenSpaceTrajectoryOptimizerConfig;
}
#include "apollo_msgs/msg/apolloplanning_hybrid_a_star_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_hybrid_a_star_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningHybridAStarConfig HybridAStarConfig;
}
#include "apollo_msgs/msg/apolloplanning_dual_variable_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_dual_variable_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningDualVariableConfig DualVariableConfig;
}
#include "apollo_msgs/msg/apolloplanning_distance_approach_trajectory_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_distance_approach_trajectory_smoother_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningDistanceApproachTrajectorySmootherConfig DistanceApproachTrajectorySmootherConfig;
}
#include "apollo_msgs/msg/apolloplanning_ipopt_solver_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_ipopt_solver_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningIpoptSolverConfig IpoptSolverConfig;
}
namespace apollo::planning::OpenSpacePreStopDeciderConfig{
	enum StopType {
		NOT_DEFINED = 0,
		PARKING = 1,
		PULL_OVER = 2,
		NARROW_STREET_U_TURN = 3
	};
}
namespace apollo::planning::OpenSpaceRoiDeciderConfig{
	enum RoiType {
		NOT_DEFINED = 0,
		PARKING = 1,
		PULL_OVER = 2,
		PARK_AND_GO = 3,
		NARROW_STREET_U_TURN = 4
	};
}
namespace apollo::planning{
	enum DualVariableMode {
		DUAL_VARIABLE_IPOPT = 0,
		DUAL_VARIABLE_IPOPTQP = 1,
		DUAL_VARIABLE_OSQP = 2,
		DUAL_VARIABLE_DEBUG = 3
	};
}