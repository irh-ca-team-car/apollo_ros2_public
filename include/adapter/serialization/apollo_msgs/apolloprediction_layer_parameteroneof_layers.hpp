#pragma once
#include "apollo_msgs/msg/apolloprediction_layer_parameteroneof_layers.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_input_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_activation_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_dense_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_batch_normalization_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_lstm_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_concatenate_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_conv1d_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_max_pool1d_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_avg_pool1d_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLayerParameteroneofLayers &msg) ;
    ApollopredictionLayerParameteroneofLayers from_json_ApollopredictionLayerParameteroneofLayers (nlohmann::json obj) ;
    template <>
    ApollopredictionLayerParameteroneofLayers from_json<ApollopredictionLayerParameteroneofLayers>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLayerParameteroneofLayers &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLayerParameteroneofLayers & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLayerParameteroneofLayers & dt);
}
