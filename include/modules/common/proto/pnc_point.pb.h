#pragma once
#include "apollo_msgs/msg/apollocommon_sl_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_sl_point.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonSLPoint SLPoint;
}
#include "apollo_msgs/msg/apollocommon_frenet_frame_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_frenet_frame_point.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonFrenetFramePoint FrenetFramePoint;
}
#include "apollo_msgs/msg/apollocommon_speed_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_speed_point.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonSpeedPoint SpeedPoint;
}
#include "apollo_msgs/msg/apollocommon_path_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_path_point.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonPathPoint PathPoint;
}
#include "apollo_msgs/msg/apollocommon_path.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_path.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonPath Path;
}
#include "apollo_msgs/msg/apollocommon_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonTrajectoryPoint TrajectoryPoint;
}
#include "apollo_msgs/msg/apollocommon_trajectory.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonTrajectory Trajectory;
}
#include "apollo_msgs/msg/apollocommon_vehicle_motion_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_motion_point.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonVehicleMotionPoint VehicleMotionPoint;
}
#include "apollo_msgs/msg/apollocommon_vehicle_motion.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_motion.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonVehicleMotion VehicleMotion;
}
#include "apollo_msgs/msg/apollocommon_gaussian_info.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_gaussian_info.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonGaussianInfo GaussianInfo;
}