#pragma once

#include "modules/planning/proto/open_space_task_config.pb.h"
#include "modules/planning/proto/task_config.pb.h"
#include "apollo_msgs/msg/apolloplanning_task_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_task_config.hpp"
#include "apollo_msgs/msg/apolloplanning_scenario_bare_intersection_unprotected_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_bare_intersection_unprotected_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioBareIntersectionUnprotectedConfig ScenarioBareIntersectionUnprotectedConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_emergency_pull_over_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_emergency_pull_over_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioEmergencyPullOverConfig ScenarioEmergencyPullOverConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_emergency_stop_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_emergency_stop_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioEmergencyStopConfig ScenarioEmergencyStopConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_park_and_go_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_park_and_go_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioParkAndGoConfig ScenarioParkAndGoConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_pull_over_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_pull_over_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioPullOverConfig ScenarioPullOverConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_stop_sign_unprotected_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_stop_sign_unprotected_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioStopSignUnprotectedConfig ScenarioStopSignUnprotectedConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_traffic_light_protected_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_traffic_light_protected_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioTrafficLightProtectedConfig ScenarioTrafficLightProtectedConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_traffic_light_unprotected_left_turn_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_traffic_light_unprotected_left_turn_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig ScenarioTrafficLightUnprotectedLeftTurnConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_traffic_light_unprotected_right_turn_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_traffic_light_unprotected_right_turn_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig ScenarioTrafficLightUnprotectedRightTurnConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_valet_parking_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_valet_parking_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioValetParkingConfig ScenarioValetParkingConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_yield_sign_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_yield_sign_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioYieldSignConfig ScenarioYieldSignConfig;
}
#include "apollo_msgs/msg/apolloplanning_stage_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_stage_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningStageConfig StageConfig;
}
#include "apollo_msgs/msg/apolloplanning_scenario_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_config.hpp"
#include "apollo_msgs/msg/apolloplanning_planner_navi_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planner_navi_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPlannerNaviConfig PlannerNaviConfig;
}
#include "apollo_msgs/msg/apolloplanning_rtk_planning_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_rtk_planning_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningRtkPlanningConfig RtkPlanningConfig;
}
#include "apollo_msgs/msg/apolloplanning_standard_planning_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_standard_planning_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningStandardPlanningConfig StandardPlanningConfig;
}
#include "apollo_msgs/msg/apolloplanning_navigation_planning_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_navigation_planning_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningNavigationPlanningConfig NavigationPlanningConfig;
}
#include "apollo_msgs/msg/apolloplanning_topic_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_topic_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTopicConfig TopicConfig;
}
#include "apollo_msgs/msg/apolloplanning_planning_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planning_config.hpp"
namespace apollo::planning::TaskConfig{
	enum TaskType {
		// deciders
		CREEP_DECIDER = 1,
		LANE_CHANGE_DECIDER = 2,
		NAVI_OBSTACLE_DECIDER = 3,
		NAVI_PATH_DECIDER = 4,
		NAVI_SPEED_DECIDER = 5,
		OPEN_SPACE_FALLBACK_DECIDER = 6,
		OPEN_SPACE_PRE_STOP_DECIDER = 7,
		OPEN_SPACE_ROI_DECIDER = 8,
		PATH_ASSESSMENT_DECIDER = 9,
		PATH_BOUNDS_DECIDER = 10,
		PATH_DECIDER = 11,
		PATH_LANE_BORROW_DECIDER = 12,
		PATH_REFERENCE_DECIDER = 13,
		PATH_REUSE_DECIDER = 14,
		RSS_DECIDER = 15,
		RULE_BASED_STOP_DECIDER = 16,
		SPEED_BOUNDS_PRIORI_DECIDER = 17,
		SPEED_BOUNDS_FINAL_DECIDER = 18,
		SPEED_DECIDER = 19,
		ST_BOUNDS_DECIDER = 20,
		// optimizers
		OPEN_SPACE_TRAJECTORY_PARTITION = 21,
		OPEN_SPACE_TRAJECTORY_PROVIDER = 22,
		PIECEWISE_JERK_NONLINEAR_SPEED_OPTIMIZER = 23,
		PIECEWISE_JERK_PATH_OPTIMIZER = 24,
		PIECEWISE_JERK_SPEED_OPTIMIZER = 25,
		SPEED_HEURISTIC_OPTIMIZER = 26,
		// other tasks
		LEARNING_MODEL_INFERENCE_TASK = 27,
		LEARNING_MODEL_INFERENCE_TRAJECTORY_TASK = 28
	};
}
namespace apollo::planning::ScenarioConfig{
	enum ScenarioType {
		LANE_FOLLOW = 0,  // default scenario
		
		// intersection involved
		BARE_INTERSECTION_UNPROTECTED = 2,
		STOP_SIGN_PROTECTED = 3,
		STOP_SIGN_UNPROTECTED = 4,
		TRAFFIC_LIGHT_PROTECTED = 5,
		TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN = 6,
		TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN = 7,
		YIELD_SIGN = 8,
		
		// parking
		PULL_OVER = 9,
		VALET_PARKING = 10,
		
		EMERGENCY_PULL_OVER = 11,
		EMERGENCY_STOP = 12,
		
		// misc
		NARROW_STREET_U_TURN = 13,
		PARK_AND_GO = 14,
		
		// learning model sample
		LEARNING_MODEL_SAMPLE = 15
	};
}
namespace apollo::planning::ScenarioConfig{
	enum StageType {
		NO_STAGE = 0,
		
		LANE_FOLLOW_DEFAULT_STAGE = 1,
		
		// bare_intersection_unprotected scenario
		BARE_INTERSECTION_UNPROTECTED_APPROACH = 200,
		BARE_INTERSECTION_UNPROTECTED_INTERSECTION_CRUISE = 201,
		
		// stop_sign_unprotected scenario
		STOP_SIGN_UNPROTECTED_PRE_STOP = 300,
		STOP_SIGN_UNPROTECTED_STOP = 301,
		STOP_SIGN_UNPROTECTED_CREEP = 302,
		STOP_SIGN_UNPROTECTED_INTERSECTION_CRUISE = 303,
		
		// traffic_light_protected scenario
		TRAFFIC_LIGHT_PROTECTED_APPROACH = 400,
		TRAFFIC_LIGHT_PROTECTED_INTERSECTION_CRUISE = 401,
		
		// traffic_light_unprotected_left_turn scenario
		TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN_APPROACH = 410,
		TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN_CREEP = 411,
		TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN_INTERSECTION_CRUISE = 412,
		
		// traffic_light_unprotected_right_turn scenario
		TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN_STOP = 420,
		TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN_CREEP = 421,
		TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN_INTERSECTION_CRUISE = 422,
		
		// pull_over scenario
		PULL_OVER_APPROACH = 500,
		PULL_OVER_RETRY_APPROACH_PARKING = 501,
		PULL_OVER_RETRY_PARKING = 502,
		
		// emergency_pull_over scenario
		EMERGENCY_PULL_OVER_SLOW_DOWN = 600,
		EMERGENCY_PULL_OVER_APPROACH = 601,
		EMERGENCY_PULL_OVER_STANDBY = 602,
		
		// emergency_pull_over scenario
		EMERGENCY_STOP_APPROACH = 610,
		EMERGENCY_STOP_STANDBY = 611,
		
		// valet parking scenario
		VALET_PARKING_APPROACHING_PARKING_SPOT = 700,
		VALET_PARKING_PARKING = 701,
		
		// park_and_go scenario
		PARK_AND_GO_CHECK = 800,
		PARK_AND_GO_CRUISE = 801,
		PARK_AND_GO_ADJUST = 802,
		PARK_AND_GO_PRE_CRUISE = 803,
		
		// yield_sign scenario
		YIELD_SIGN_APPROACH = 900,
		YIELD_SIGN_CREEP = 901,
		
		// learning_model_sample scenario
		LEARNING_MODEL_RUN = 1000
	};
}
namespace apollo::planning{
	enum PlannerType {
		RTK = 0,
		PUBLIC_ROAD = 1,  // public road planner
		NAVI = 2,         // navigation planner
		LATTICE = 3      // lattice planner
	};
}
namespace apollo::planning::PlanningConfig{
	enum PlanningLearningMode {
		NO_LEARNING = 0,
		E2E = 1,
		HYBRID = 2,
		RL_TEST = 3,
		E2E_TEST = 4,
		HYBRID_TEST = 5
	};
}
#include "modules/planning/proto/planning_config_name.pb.h"
