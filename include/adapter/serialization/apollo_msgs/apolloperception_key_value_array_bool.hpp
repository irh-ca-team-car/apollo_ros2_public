#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_array_bool.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayBool &msg) ;
    ApolloperceptionKeyValueArrayBool from_json_ApolloperceptionKeyValueArrayBool (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueArrayBool from_json<ApolloperceptionKeyValueArrayBool>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayBool &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayBool & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayBool & dt);
}
