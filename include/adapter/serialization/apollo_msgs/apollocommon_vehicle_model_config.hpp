#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_model_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_rear_centered_kinematic_bicycle_model_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_com_centered_dynamic_bicycle_model_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_mlp_model_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleModelConfig &msg) ;
    ApollocommonVehicleModelConfig from_json_ApollocommonVehicleModelConfig (nlohmann::json obj) ;
    template <>
    ApollocommonVehicleModelConfig from_json<ApollocommonVehicleModelConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleModelConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleModelConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleModelConfig & dt);
}
