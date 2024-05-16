#pragma once
#include "modules/map/proto/map_id.pb.h"
#include "modules/map/proto/map_geometry.pb.h"
#include "apollo_msgs/msg/apollohdmap_clear_area.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_clear_area.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapClearArea ClearArea;
}