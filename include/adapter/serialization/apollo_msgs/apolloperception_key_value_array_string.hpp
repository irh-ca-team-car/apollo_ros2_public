#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_array_string.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayString &msg) ;
    ApolloperceptionKeyValueArrayString from_json_ApolloperceptionKeyValueArrayString (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueArrayString from_json<ApolloperceptionKeyValueArrayString>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayString &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayString & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayString & dt);
}
