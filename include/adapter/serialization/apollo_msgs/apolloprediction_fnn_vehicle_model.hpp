#pragma once
#include "apollo_msgs/msg/apolloprediction_fnn_vehicle_model.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_vector.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_layer.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionFnnVehicleModel &msg) ;
    ApollopredictionFnnVehicleModel from_json_ApollopredictionFnnVehicleModel (nlohmann::json obj) ;
    template <>
    ApollopredictionFnnVehicleModel from_json<ApollopredictionFnnVehicleModel>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionFnnVehicleModel &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionFnnVehicleModel & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionFnnVehicleModel & dt);
}
