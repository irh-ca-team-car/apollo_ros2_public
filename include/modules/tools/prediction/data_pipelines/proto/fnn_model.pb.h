#pragma once
#include "apollo_msgs/msg/vector.hpp"
#include "adapter/serialization/apollo_msgs/vector.hpp"
namespace {
	typedef apollo_msgs::msg::Vector Vector;
}
#include "apollo_msgs/msg/matrix.hpp"
#include "adapter/serialization/apollo_msgs/matrix.hpp"
namespace {
	typedef apollo_msgs::msg::Matrix Matrix;
}
#include "apollo_msgs/msg/layer.hpp"
#include "adapter/serialization/apollo_msgs/layer.hpp"
#include "apollo_msgs/msg/fnn_model.hpp"
#include "adapter/serialization/apollo_msgs/fnn_model.hpp"
namespace {
	typedef apollo_msgs::msg::FnnModel FnnModel;
}
namespace ::Layer{
	enum ActivationFunc {
		RELU = 0,
		TANH = 1,
		SIGMOID = 2,
		SOFTMAX = 3
	};
}