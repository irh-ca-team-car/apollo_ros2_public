#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_bool.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueBool &msg) ;
    ApolloperceptionKeyValueBool from_json_ApolloperceptionKeyValueBool (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueBool from_json<ApolloperceptionKeyValueBool>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueBool &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueBool & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueBool & dt);
}
