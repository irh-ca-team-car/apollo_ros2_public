#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_int.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueInt &msg) ;
    ApolloperceptionKeyValueInt from_json_ApolloperceptionKeyValueInt (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueInt from_json<ApolloperceptionKeyValueInt>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueInt &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueInt & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueInt & dt);
}
