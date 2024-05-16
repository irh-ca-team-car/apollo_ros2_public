#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/localization/proto/pose.pb.h"
#include "apollo_msgs/msg/apollolocalization_corrected_imu.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_corrected_imu.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationCorrectedImu CorrectedImu;
}