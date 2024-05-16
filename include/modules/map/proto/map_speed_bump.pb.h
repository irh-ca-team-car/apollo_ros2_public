#pragma once
#include "modules/map/proto/map_id.pb.h"
#include "modules/map/proto/map_geometry.pb.h"
#include "apollo_msgs/msg/apollohdmap_speed_bump.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_speed_bump.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapSpeedBump SpeedBump;
}