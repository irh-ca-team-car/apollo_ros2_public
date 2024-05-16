#pragma once
#include "modules/prediction/proto/network_layers.pb.h"
#include "apollo_msgs/msg/apolloprediction_verification_sample.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_verification_sample.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionVerificationSample VerificationSample;
}
#include "apollo_msgs/msg/apolloprediction_performance.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_performance.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionPerformance Performance;
}
#include "apollo_msgs/msg/apolloprediction_net_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_net_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionNetParameter NetParameter;
}