#pragma once
#include "apollo_msgs/msg/apolloplanning_st_drivable_boundary_instance.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_st_drivable_boundary_instance.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningSTDrivableBoundaryInstance STDrivableBoundaryInstance;
}
#include "apollo_msgs/msg/apolloplanning_st_drivable_boundary.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_st_drivable_boundary.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningSTDrivableBoundary STDrivableBoundary;
}