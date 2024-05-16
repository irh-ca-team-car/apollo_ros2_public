#pragma once
#include "apollo_msgs/msg/apollodata_smart_record_trigger.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodata_record_segment_setting.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_trigger.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataSmartRecordTrigger &msg) ;
    ApollodataSmartRecordTrigger from_json_ApollodataSmartRecordTrigger (nlohmann::json obj) ;
    template <>
    ApollodataSmartRecordTrigger from_json<ApollodataSmartRecordTrigger>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataSmartRecordTrigger &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataSmartRecordTrigger & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataSmartRecordTrigger & dt);
}
