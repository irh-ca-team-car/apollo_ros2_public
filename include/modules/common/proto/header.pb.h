#pragma once
#include "modules/common/proto/error_code.pb.h"
#include "apollo_msgs/msg/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "std_msgs/msg/header.h"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonHeader Header;
}