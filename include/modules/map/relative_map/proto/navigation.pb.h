#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/map/proto/map.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "apollo_msgs/msg/apollorelative_map_navigation_path.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_navigation_path.hpp"
namespace apollo::relative_map{
	typedef apollo_msgs::msg::ApollorelativeMapNavigationPath NavigationPath;
}
#include "apollo_msgs/msg/apollorelative_map_navigation_info.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_navigation_info.hpp"
namespace apollo::relative_map{
	typedef apollo_msgs::msg::ApollorelativeMapNavigationInfo NavigationInfo;
}
#include "apollo_msgs/msg/apollorelative_map_map_msg.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_map_msg.hpp"