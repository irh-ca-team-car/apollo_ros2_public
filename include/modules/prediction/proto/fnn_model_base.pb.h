#pragma once
#include "apollo_msgs/msg/apolloprediction_vector.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_vector.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionVector Vector;
}
#include "apollo_msgs/msg/apolloprediction_matrix.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_matrix.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionMatrix Matrix;
}
#include "apollo_msgs/msg/apolloprediction_layer.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_layer.hpp"
namespace apollo::prediction::Layer{
	enum ActivationFunc {
		RELU = 0,
		TANH = 1,
		SIGMOID = 2,
		SOFTMAX = 3
	};
}