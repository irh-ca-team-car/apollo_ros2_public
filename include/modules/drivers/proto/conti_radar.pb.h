#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/drivers/radar/conti_radar/proto/conti_radar_conf.pb.h"
#include "apollo_msgs/msg/apollodrivers_cluster_list_status600.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_cluster_list_status600.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversClusterListStatus600 ClusterListStatus_600;
}
#include "apollo_msgs/msg/apollodrivers_object_list_status60_a.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_object_list_status60_a.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversObjectListStatus60A ObjectListStatus_60A;
}
#include "apollo_msgs/msg/apollodrivers_radar_state201.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_radar_state201.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversRadarState201 RadarState_201;
}
#include "apollo_msgs/msg/apollodrivers_conti_radar_obs.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_conti_radar_obs.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversContiRadarObs ContiRadarObs;
}
#include "apollo_msgs/msg/apollodrivers_conti_radar.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_conti_radar.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversContiRadar ContiRadar;
}