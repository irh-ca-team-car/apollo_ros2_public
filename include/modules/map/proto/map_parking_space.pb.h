#pragma once
#include "modules/map/proto/map_geometry.pb.h"
#include "modules/map/proto/map_id.pb.h"
#include "apollo_msgs/msg/apollohdmap_parking_space.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_parking_space.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapParkingSpace ParkingSpace;
}
#include "apollo_msgs/msg/apollohdmap_parking_lot.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_parking_lot.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapParkingLot ParkingLot;
}