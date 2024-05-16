#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollodriversgnss_imu.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_imu.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssImu Imu;
}