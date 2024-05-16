#pragma once
#include "modules/planning/proto/math/fem_pos_deviation_smoother_config.pb.h"
#include "modules/planning/proto/task_config.pb.h"
#include "apollo_msgs/msg/apolloplanning_planner_open_space_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planner_open_space_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPlannerOpenSpaceConfig PlannerOpenSpaceConfig;
}
#include "apollo_msgs/msg/apolloplanning_roi_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_roi_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningROIConfig ROIConfig;
}
#include "apollo_msgs/msg/apolloplanning_warm_start_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_warm_start_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningWarmStartConfig WarmStartConfig;
}
#include "apollo_msgs/msg/apolloplanning_dual_variable_warm_start_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_dual_variable_warm_start_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningDualVariableWarmStartConfig DualVariableWarmStartConfig;
}
#include "apollo_msgs/msg/apolloplanning_distance_approach_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_distance_approach_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningDistanceApproachConfig DistanceApproachConfig;
}
#include "apollo_msgs/msg/apolloplanning_ipopt_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_ipopt_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningIpoptConfig IpoptConfig;
}
#include "apollo_msgs/msg/apolloplanning_osqp_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_osqp_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningOSQPConfig OSQPConfig;
}
#include "apollo_msgs/msg/apolloplanning_iterative_anchoring_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_iterative_anchoring_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningIterativeAnchoringConfig IterativeAnchoringConfig;
}
#include "apollo_msgs/msg/apolloplanning_trajectory_partition_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_trajectory_partition_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTrajectoryPartitionConfig TrajectoryPartitionConfig;
}
namespace apollo::planning{
	enum DualWarmUpMode {
		IPOPT = 0,
		IPOPTQP = 1,
		OSQP = 2,
		DEBUG = 3,
		SLACKQP = 4
	};
}
namespace apollo::planning{
	enum DistanceApproachMode {
		DISTANCE_APPROACH_IPOPT = 0,
		DISTANCE_APPROACH_IPOPT_CUDA = 1,
		DISTANCE_APPROACH_IPOPT_FIXED_TS = 2,
		DISTANCE_APPROACH_IPOPT_FIXED_DUAL = 3,
		DISTANCE_APPROACH_IPOPT_RELAX_END = 4,
		DISTANCE_APPROACH_IPOPT_RELAX_END_SLACK = 5
	};
}