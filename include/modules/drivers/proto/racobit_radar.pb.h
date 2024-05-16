#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/drivers/radar/racobit_radar/proto/racobit_radar_conf.pb.h"
#include "apollo_msgs/msg/apollodrivers_racobit_cluster_list_status600.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_cluster_list_status600.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversRacobitClusterListStatus600 RacobitClusterListStatus_600;
}
#include "apollo_msgs/msg/apollodrivers_racobit_object_list_status60_a.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_object_list_status60_a.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversRacobitObjectListStatus60A RacobitObjectListStatus_60A;
}
#include "apollo_msgs/msg/apollodrivers_racobit_radar_state201.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_radar_state201.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversRacobitRadarState201 RacobitRadarState_201;
}
#include "apollo_msgs/msg/apollodrivers_racobit_radar_obs.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_radar_obs.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversRacobitRadarObs RacobitRadarObs;
}
#include "apollo_msgs/msg/apollodrivers_racobit_radar.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_radar.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversRacobitRadar RacobitRadar;
}