#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_array_float.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayFloat &msg) ;
    ApolloperceptionKeyValueArrayFloat from_json_ApolloperceptionKeyValueArrayFloat (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueArrayFloat from_json<ApolloperceptionKeyValueArrayFloat>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayFloat &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayFloat & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayFloat & dt);
}
