#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_param.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_extrinsics.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleConfig &msg) ;
    ApollocommonVehicleConfig from_json_ApollocommonVehicleConfig (nlohmann::json obj) ;
    template <>
    ApollocommonVehicleConfig from_json<ApollocommonVehicleConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleConfig & dt);
}
