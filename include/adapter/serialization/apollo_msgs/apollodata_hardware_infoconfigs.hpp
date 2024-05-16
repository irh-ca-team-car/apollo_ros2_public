#pragma once
#include "apollo_msgs/msg/apollodata_hardware_infoconfigs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataHardwareInfoconfigs &msg) ;
    ApollodataHardwareInfoconfigs from_json_ApollodataHardwareInfoconfigs (nlohmann::json obj) ;
    template <>
    ApollodataHardwareInfoconfigs from_json<ApollodataHardwareInfoconfigs>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataHardwareInfoconfigs &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataHardwareInfoconfigs & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataHardwareInfoconfigs & dt);
}
