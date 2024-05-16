#pragma once
#include "modules/prediction/proto/fnn_model_base.pb.h"
#include "apollo_msgs/msg/apolloprediction_fnn_vehicle_model.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_fnn_vehicle_model.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionFnnVehicleModel FnnVehicleModel;
}