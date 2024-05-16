#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_motion.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_motion_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleMotion &msg) ;
    ApollocommonVehicleMotion from_json_ApollocommonVehicleMotion (nlohmann::json obj) ;
    template <>
    ApollocommonVehicleMotion from_json<ApollocommonVehicleMotion>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleMotion &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleMotion & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleMotion & dt);
}
