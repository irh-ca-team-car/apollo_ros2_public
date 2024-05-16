#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_float.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueFloat &msg) ;
    ApolloperceptionKeyValueFloat from_json_ApolloperceptionKeyValueFloat (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueFloat from_json<ApolloperceptionKeyValueFloat>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueFloat &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueFloat & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueFloat & dt);
}
