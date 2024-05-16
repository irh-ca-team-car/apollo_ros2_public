#pragma once
#include "apollo_msgs/msg/apollodata_hardware_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodata_hardware_infoconfigs.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataHardwareInfo &msg) ;
    ApollodataHardwareInfo from_json_ApollodataHardwareInfo (nlohmann::json obj) ;
    template <>
    ApollodataHardwareInfo from_json<ApollodataHardwareInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataHardwareInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataHardwareInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataHardwareInfo & dt);
}
