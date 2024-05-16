#pragma once
#include "apollo_msgs/msg/apollodata_smart_recorder_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataSmartRecorderStatus &msg) ;
    ApollodataSmartRecorderStatus from_json_ApollodataSmartRecorderStatus (nlohmann::json obj) ;
    template <>
    ApollodataSmartRecorderStatus from_json<ApollodataSmartRecorderStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataSmartRecorderStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataSmartRecorderStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataSmartRecorderStatus & dt);
}
