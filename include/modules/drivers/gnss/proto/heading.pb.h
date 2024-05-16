#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodriversgnss_heading.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_heading.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssHeading Heading;
}