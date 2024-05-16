#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollolocalization_integ_sins_pva.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_integ_sins_pva.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationIntegSinsPva IntegSinsPva;
}