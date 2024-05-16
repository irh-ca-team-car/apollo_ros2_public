#pragma once
#include "apollo_msgs/msg/apolloprediction_tensor_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_tensor_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionTensorParameter TensorParameter;
}
#include "apollo_msgs/msg/apolloprediction_input_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_input_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionInputParameter InputParameter;
}
#include "apollo_msgs/msg/apolloprediction_dense_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_dense_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionDenseParameter DenseParameter;
}
#include "apollo_msgs/msg/apolloprediction_conv1d_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_conv1d_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionConv1dParameter Conv1dParameter;
}
#include "apollo_msgs/msg/apolloprediction_max_pool1d_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_max_pool1d_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionMaxPool1dParameter MaxPool1dParameter;
}
#include "apollo_msgs/msg/apolloprediction_avg_pool1d_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_avg_pool1d_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionAvgPool1dParameter AvgPool1dParameter;
}
#include "apollo_msgs/msg/apolloprediction_batch_normalization_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_batch_normalization_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionBatchNormalizationParameter BatchNormalizationParameter;
}
#include "apollo_msgs/msg/apolloprediction_lstm_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lstm_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionLSTMParameter LSTMParameter;
}
#include "apollo_msgs/msg/apolloprediction_activation_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_activation_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionActivationParameter ActivationParameter;
}
#include "apollo_msgs/msg/apolloprediction_concatenate_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_concatenate_parameter.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionConcatenateParameter ConcatenateParameter;
}
#include "apollo_msgs/msg/apolloprediction_layer_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_layer_parameter.hpp"