#pragma once
#include "modules/map/proto/map_geometry.pb.h"
#include "modules/map/proto/map_id.pb.h"
#include "apollo_msgs/msg/apollohdmap_crosswalk.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_crosswalk.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapCrosswalk Crosswalk;
}