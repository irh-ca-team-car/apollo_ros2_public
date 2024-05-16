#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_motion_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleMotionPoint &msg) ;
    ApollocommonVehicleMotionPoint from_json_ApollocommonVehicleMotionPoint (nlohmann::json obj) ;
    template <>
    ApollocommonVehicleMotionPoint from_json<ApollocommonVehicleMotionPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleMotionPoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleMotionPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleMotionPoint & dt);
}
