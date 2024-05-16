#pragma once
#include "apollo_msgs/msg/apollodata_vehicle_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_license.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_canbus_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_control_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataVehicleInfo &msg) ;
    ApollodataVehicleInfo from_json_ApollodataVehicleInfo (nlohmann::json obj) ;
    template <>
    ApollodataVehicleInfo from_json<ApollodataVehicleInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataVehicleInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataVehicleInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataVehicleInfo & dt);
}
