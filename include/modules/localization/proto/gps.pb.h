#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/localization/proto/pose.pb.h"
#include "apollo_msgs/msg/apollolocalization_gps.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_gps.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationGps Gps;
}