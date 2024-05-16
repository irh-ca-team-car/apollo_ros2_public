#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "modules/planning/proto/planning_config.pb.h"
#include "modules/routing/proto/routing.pb.h"
#include "apollo_msgs/msg/apolloplanning_bare_intersection_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_bare_intersection_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningBareIntersectionStatus BareIntersectionStatus;
}
#include "apollo_msgs/msg/apolloplanning_change_lane_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_change_lane_status.hpp"
#include "apollo_msgs/msg/apolloplanning_creep_decider_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_creep_decider_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningCreepDeciderStatus CreepDeciderStatus;
}
#include "apollo_msgs/msg/apolloplanning_stop_time.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_stop_time.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningStopTime StopTime;
}
#include "apollo_msgs/msg/apolloplanning_crosswalk_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_crosswalk_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningCrosswalkStatus CrosswalkStatus;
}
#include "apollo_msgs/msg/apolloplanning_destination_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_destination_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningDestinationStatus DestinationStatus;
}
#include "apollo_msgs/msg/apolloplanning_emergency_stop_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_emergency_stop_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningEmergencyStopStatus EmergencyStopStatus;
}
#include "apollo_msgs/msg/apolloplanning_open_space_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningOpenSpaceStatus OpenSpaceStatus;
}
#include "apollo_msgs/msg/apolloplanning_park_and_go_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_park_and_go_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningParkAndGoStatus ParkAndGoStatus;
}
#include "apollo_msgs/msg/apolloplanning_path_decider_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_decider_status.hpp"
#include "apollo_msgs/msg/apolloplanning_pull_over_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_pull_over_status.hpp"
#include "apollo_msgs/msg/apolloplanning_rerouting_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_rerouting_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningReroutingStatus ReroutingStatus;
}
#include "apollo_msgs/msg/apolloplanning_speed_decider_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_speed_decider_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningSpeedDeciderStatus SpeedDeciderStatus;
}
#include "apollo_msgs/msg/apolloplanning_scenario_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningScenarioStatus ScenarioStatus;
}
#include "apollo_msgs/msg/apolloplanning_stop_sign_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_stop_sign_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningStopSignStatus StopSignStatus;
}
#include "apollo_msgs/msg/apolloplanning_traffic_light_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTrafficLightStatus TrafficLightStatus;
}
#include "apollo_msgs/msg/apolloplanning_yield_sign_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_yield_sign_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningYieldSignStatus YieldSignStatus;
}
#include "apollo_msgs/msg/apolloplanning_planning_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planning_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPlanningStatus PlanningStatus;
}
namespace apollo::planning::ChangeLaneStatus{
	enum Status {
		IN_CHANGE_LANE = 1,        // during change lane state
		CHANGE_LANE_FAILED = 2,    // change lane failed
		CHANGE_LANE_FINISHED = 3  // change lane finished
	};
}
namespace apollo::planning::PathDeciderStatus{
	enum LaneBorrowDirection {
		LEFT_BORROW = 1,   // borrow left neighbor lane
		RIGHT_BORROW = 2  // borrow right neighbor lane
	};
}
namespace apollo::planning::PullOverStatus{
	enum PullOverType {
		PULL_OVER = 1,            // pull-over upon destination arrival
		EMERGENCY_PULL_OVER = 2  // emergency pull-over
	};
}