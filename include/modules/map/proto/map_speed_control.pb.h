#pragma once
#include "modules/map/proto/map_geometry.pb.h"
#include "apollo_msgs/msg/apollohdmap_speed_control.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_speed_control.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapSpeedControl SpeedControl;
}
#include "apollo_msgs/msg/apollohdmap_speed_controls.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_speed_controls.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapSpeedControls SpeedControls;
}