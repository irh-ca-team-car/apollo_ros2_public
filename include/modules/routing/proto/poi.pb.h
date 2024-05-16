#pragma once
#include "modules/routing/proto/routing.pb.h"
#include "apollo_msgs/msg/apollorouting_landmark.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_landmark.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingLandmark Landmark;
}
#include "apollo_msgs/msg/apollorouting_poi.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_poi.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingPOI POI;
}