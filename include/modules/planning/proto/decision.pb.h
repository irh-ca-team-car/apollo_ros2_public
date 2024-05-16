#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/vehicle_signal.pb.h"
#include "modules/routing/proto/routing.pb.h"
#include "apollo_msgs/msg/apolloplanning_target_lane.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_target_lane.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTargetLane TargetLane;
}
#include "apollo_msgs/msg/apolloplanning_object_stop.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_stop.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningObjectStop ObjectStop;
}
#include "apollo_msgs/msg/apolloplanning_object_nudge.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_nudge.hpp"
#include "apollo_msgs/msg/apolloplanning_object_yield.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_yield.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningObjectYield ObjectYield;
}
#include "apollo_msgs/msg/apolloplanning_object_follow.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_follow.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningObjectFollow ObjectFollow;
}
#include "apollo_msgs/msg/apolloplanning_object_overtake.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_overtake.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningObjectOvertake ObjectOvertake;
}
#include "apollo_msgs/msg/apolloplanning_object_side_pass.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_side_pass.hpp"
#include "apollo_msgs/msg/apolloplanning_object_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_status.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningObjectStatus ObjectStatus;
}
#include "apollo_msgs/msg/apolloplanning_object_motion_type.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_motion_type.hpp"
#include "apollo_msgs/msg/apolloplanning_object_decision_type.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision_type.hpp"
#include "apollo_msgs/msg/apolloplanning_object_decision.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningObjectDecision ObjectDecision;
}
#include "apollo_msgs/msg/apolloplanning_object_decisions.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_decisions.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningObjectDecisions ObjectDecisions;
}
#include "apollo_msgs/msg/apolloplanning_main_stop.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_stop.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningMainStop MainStop;
}
#include "apollo_msgs/msg/apolloplanning_main_emergency_stop.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_emergency_stop.hpp"
#include "apollo_msgs/msg/apolloplanning_main_cruise.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_cruise.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningMainCruise MainCruise;
}
#include "apollo_msgs/msg/apolloplanning_main_change_lane.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_change_lane.hpp"
#include "apollo_msgs/msg/apolloplanning_main_mission_complete.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_mission_complete.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningMainMissionComplete MainMissionComplete;
}
#include "apollo_msgs/msg/apolloplanning_main_not_ready.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_not_ready.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningMainNotReady MainNotReady;
}
#include "apollo_msgs/msg/apolloplanning_main_parking.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_parking.hpp"
#include "apollo_msgs/msg/apolloplanning_main_decision.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_decision.hpp"
#include "apollo_msgs/msg/apolloplanning_decision_result.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_decision_result.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningDecisionResult DecisionResult;
}
namespace apollo::planning{
	enum StopReasonCode {
		STOP_REASON_HEAD_VEHICLE = 1,
		STOP_REASON_DESTINATION = 2,
		STOP_REASON_PEDESTRIAN = 3,
		STOP_REASON_OBSTACLE = 4,
		STOP_REASON_PREPARKING = 5,
		STOP_REASON_SIGNAL = 100,  // only for red signal
		STOP_REASON_STOP_SIGN = 101,
		STOP_REASON_YIELD_SIGN = 102,
		STOP_REASON_CLEAR_ZONE = 103,
		STOP_REASON_CROSSWALK = 104,
		STOP_REASON_CREEPER = 105,
		STOP_REASON_REFERENCE_END = 106,  // end of the reference_line
		STOP_REASON_YELLOW_SIGNAL = 107,  // yellow signal
		STOP_REASON_PULL_OVER = 108,      // pull over
		STOP_REASON_SIDEPASS_SAFETY = 109,
		STOP_REASON_PRE_OPEN_SPACE_STOP = 200,
		STOP_REASON_LANE_CHANGE_URGENCY = 201,
		STOP_REASON_EMERGENCY = 202
	};
}
namespace apollo::planning::ObjectNudge{
	enum Type {
		LEFT_NUDGE = 1,   // drive from the left side to nudge a static obstacle
		RIGHT_NUDGE = 2,  // drive from the right side to nudge a static obstacle
		DYNAMIC_LEFT_NUDGE = 3,   // drive from the left side to nudge a dynamic obstacle
		DYNAMIC_RIGHT_NUDGE = 4  // drive from the right side to nudge a dynamic obstacle
	};
}
namespace apollo::planning::ObjectSidePass{
	enum Type {
		LEFT = 1,
		RIGHT = 2
	};
}
namespace apollo::planning::MainEmergencyStop{
	enum ReasonCode {
		ESTOP_REASON_INTERNAL_ERR = 1,
		ESTOP_REASON_COLLISION = 2,
		ESTOP_REASON_ST_FIND_PATH = 3,
		ESTOP_REASON_ST_MAKE_DECISION = 4,
		ESTOP_REASON_SENSOR_ERROR = 5
	};
}
namespace apollo::planning::MainChangeLane{
	enum Type {
		LEFT = 1,
		RIGHT = 2
	};
}
namespace apollo::planning::MainParking{
	enum ParkingStatus {
		// TODO(QiL): implement and expand to more enums
		IN_PARKING = 1
	};
}
#include "modules/planning/proto/decision_name.pb.h"