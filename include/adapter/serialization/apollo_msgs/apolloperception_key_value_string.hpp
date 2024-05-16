#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_string.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueString &msg) ;
    ApolloperceptionKeyValueString from_json_ApolloperceptionKeyValueString (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueString from_json<ApolloperceptionKeyValueString>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueString &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueString & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueString & dt);
}
