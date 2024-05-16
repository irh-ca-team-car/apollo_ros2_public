#pragma once
#include "apollo_msgs/msg/apollodata_record_segment_setting.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataRecordSegmentSetting &msg) ;
    ApollodataRecordSegmentSetting from_json_ApollodataRecordSegmentSetting (nlohmann::json obj) ;
    template <>
    ApollodataRecordSegmentSetting from_json<ApollodataRecordSegmentSetting>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataRecordSegmentSetting &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataRecordSegmentSetting & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataRecordSegmentSetting & dt);
}
