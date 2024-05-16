#pragma once
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/common/proto/drive_state.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/map/proto/map_id.pb.h"
#include "modules/planning/proto/decision.pb.h"
#include "modules/planning/proto/planning_internal.pb.h"
#include "apollo_msgs/msg/apolloplanning_e_stop.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_e_stop.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningEStop EStop;
}
#include "apollo_msgs/msg/apolloplanning_task_stats.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_task_stats.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTaskStats TaskStats;
}
#include "apollo_msgs/msg/apolloplanning_latency_stats.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_latency_stats.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningLatencyStats LatencyStats;
}
#include "apollo_msgs/msg/apolloplanning_rss_info.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_rss_info.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningRSSInfo RSSInfo;
}
#include "apollo_msgs/msg/apolloplanning_adc_trajectory_critical_region.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_adc_trajectory_critical_region.hpp"
namespace apollo::planning::ADCTrajectory{
	typedef apollo_msgs::msg::ApolloplanningADCTrajectoryCriticalRegion CriticalRegion;
}
#include "apollo_msgs/msg/apolloplanning_adc_trajectory.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_adc_trajectory.hpp"
namespace apollo::planning::ADCTrajectory{
	enum RightOfWayStatus {
		UNPROTECTED = 0,
		PROTECTED = 1
	};
}
namespace apollo::planning::ADCTrajectory{
	enum TrajectoryType {
		UNKNOWN = 0,
		NORMAL = 1,
		PATH_FALLBACK = 2,
		SPEED_FALLBACK = 3,
		PATH_REUSED = 4
	};
}
