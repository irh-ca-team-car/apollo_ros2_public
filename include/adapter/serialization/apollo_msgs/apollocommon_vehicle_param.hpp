#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_id.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleParam &msg) ;
    ApollocommonVehicleParam from_json_ApollocommonVehicleParam (nlohmann::json obj) ;
    template <>
    ApollocommonVehicleParam from_json<ApollocommonVehicleParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleParam & dt);
}
