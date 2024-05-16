#pragma once
#include "modules/map/proto/map_id.pb.h"
#include "modules/map/proto/map_geometry.pb.h"
#include "apollo_msgs/msg/apollohdmap_yield_sign.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_yield_sign.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapYieldSign YieldSign;
}