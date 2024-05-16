#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollolocalization_pose.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_pose.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationPose Pose;
}