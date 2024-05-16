#pragma once
#include "apollo_msgs/msg/apolloperception_vehicle_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_motion_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionVehicleStatus &msg) ;
    ApolloperceptionVehicleStatus from_json_ApolloperceptionVehicleStatus (nlohmann::json obj) ;
    template <>
    ApolloperceptionVehicleStatus from_json<ApolloperceptionVehicleStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionVehicleStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionVehicleStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionVehicleStatus & dt);
}
