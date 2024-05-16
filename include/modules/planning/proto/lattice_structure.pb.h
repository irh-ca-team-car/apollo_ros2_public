#pragma once
#include "apollo_msgs/msg/apolloplanning_stop_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_stop_point.hpp"
#include "apollo_msgs/msg/apolloplanning_planning_target.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planning_target.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPlanningTarget PlanningTarget;
}
namespace apollo::planning::StopPoint{
	enum Type {
		HARD = 0,
		SOFT = 1
	};
}