#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/dreamview/proto/chart.pb.h"
#include "modules/map/relative_map/proto/navigation.pb.h"
#include "modules/routing/proto/routing.pb.h"
#include "modules/perception/proto/traffic_light_detection.pb.h"
#include "modules/planning/proto/sl_boundary.pb.h"
#include "modules/planning/proto/decision.pb.h"
#include "modules/planning/proto/planning_config.pb.h"
#include "apollo_msgs/msg/apolloplanning_internal_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalDebug Debug;
}
#include "apollo_msgs/msg/apolloplanning_internal_speed_plan.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_speed_plan.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalSpeedPlan SpeedPlan;
}
#include "apollo_msgs/msg/apolloplanning_internal_st_graph_boundary_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_boundary_debug.hpp"
#include "apollo_msgs/msg/apolloplanning_internal_sl_frame_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_sl_frame_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalSLFrameDebug SLFrameDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_st_graph_speed_constraint.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_speed_constraint.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalSTGraphSpeedConstraint STGraphSpeedConstraint;
}
#include "apollo_msgs/msg/apolloplanning_internal_st_graph_kernel_cuise_ref.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_kernel_cuise_ref.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalSTGraphKernelCuiseRef STGraphKernelCuiseRef;
}
#include "apollo_msgs/msg/apolloplanning_internal_st_graph_kernel_follow_ref.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_kernel_follow_ref.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalSTGraphKernelFollowRef STGraphKernelFollowRef;
}
#include "apollo_msgs/msg/apolloplanning_internal_st_graph_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalSTGraphDebug STGraphDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_signal_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_signal_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalSignalDebug SignalDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_signal_light_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_signal_light_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalSignalLightDebug SignalLightDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_decision_tag.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_decision_tag.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalDecisionTag DecisionTag;
}
#include "apollo_msgs/msg/apolloplanning_internal_obstacle_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_obstacle_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalObstacleDebug ObstacleDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_reference_line_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_reference_line_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalReferenceLineDebug ReferenceLineDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_sample_layer_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_sample_layer_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalSampleLayerDebug SampleLayerDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_dp_poly_graph_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_dp_poly_graph_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalDpPolyGraphDebug DpPolyGraphDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_scenario_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_scenario_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalScenarioDebug ScenarioDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_trajectories.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_trajectories.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalTrajectories Trajectories;
}
#include "apollo_msgs/msg/apolloplanning_internal_open_space_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_open_space_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalOpenSpaceDebug OpenSpaceDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_smoother_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_smoother_debug.hpp"
#include "apollo_msgs/msg/apolloplanning_internal_pull_over_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_pull_over_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalPullOverDebug PullOverDebug;
}
#include "apollo_msgs/msg/apolloplanning_internal_planning_data.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_planning_data.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalPlanningData PlanningData;
}
#include "apollo_msgs/msg/apolloplanning_internal_lattice_st_pixel.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_lattice_st_pixel.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalLatticeStPixel LatticeStPixel;
}
#include "apollo_msgs/msg/apolloplanning_internal_lattice_st_training.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_lattice_st_training.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalLatticeStTraining LatticeStTraining;
}
#include "apollo_msgs/msg/apolloplanning_internal_cost_components.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_cost_components.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalCostComponents CostComponents;
}
#include "apollo_msgs/msg/apolloplanning_internal_auto_tuning_training_data.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_auto_tuning_training_data.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalAutoTuningTrainingData AutoTuningTrainingData;
}
#include "apollo_msgs/msg/apolloplanning_internal_cloud_reference_line_request.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_cloud_reference_line_request.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalCloudReferenceLineRequest CloudReferenceLineRequest;
}
#include "apollo_msgs/msg/apolloplanning_internal_cloud_reference_line_routing_request.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_cloud_reference_line_routing_request.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalCloudReferenceLineRoutingRequest CloudReferenceLineRoutingRequest;
}
#include "apollo_msgs/msg/apolloplanning_internal_cloud_reference_line_response.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_cloud_reference_line_response.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalCloudReferenceLineResponse CloudReferenceLineResponse;
}
#include "apollo_msgs/msg/apolloplanning_internal_hybrid_model_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_hybrid_model_debug.hpp"
namespace apollo::planningInternal{
	typedef apollo_msgs::msg::ApolloplanningInternalHybridModelDebug HybridModelDebug;
}
namespace apollo::planningInternal::StGraphBoundaryDebug{
	enum StBoundaryType {
		ST_BOUNDARY_TYPE_UNKNOWN = 1,
		ST_BOUNDARY_TYPE_STOP = 2,
		ST_BOUNDARY_TYPE_FOLLOW = 3,
		ST_BOUNDARY_TYPE_YIELD = 4,
		ST_BOUNDARY_TYPE_OVERTAKE = 5,
		ST_BOUNDARY_TYPE_KEEP_CLEAR = 6,
		ST_BOUNDARY_TYPE_DRIVABLE_REGION = 7
	};
}
namespace apollo::planningInternal::SmootherDebug{
	enum SmootherType {
		SMOOTHER_NONE = 1,
		SMOOTHER_CLOSE_STOP = 2
	};
}