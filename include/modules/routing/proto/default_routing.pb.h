#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollorouting_default_routing.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_default_routing.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingDefaultRouting DefaultRouting;
}
#include "apollo_msgs/msg/apollorouting_default_routings.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_default_routings.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingDefaultRoutings DefaultRoutings;
}