#pragma once
#include "apollo_msgs/msg/apolloplanning_stats_group.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_stats_group.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningStatsGroup StatsGroup;
}
#include "apollo_msgs/msg/apolloplanning_planning_stats.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planning_stats.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningPlanningStats PlanningStats;
}