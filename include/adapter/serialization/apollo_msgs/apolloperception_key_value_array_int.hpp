#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_array_int.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayInt &msg) ;
    ApolloperceptionKeyValueArrayInt from_json_ApolloperceptionKeyValueArrayInt (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueArrayInt from_json<ApolloperceptionKeyValueArrayInt>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayInt &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayInt & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayInt & dt);
}
