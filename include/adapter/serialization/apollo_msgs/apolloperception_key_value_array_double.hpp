#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_array_double.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayDouble &msg) ;
    ApolloperceptionKeyValueArrayDouble from_json_ApolloperceptionKeyValueArrayDouble (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueArrayDouble from_json<ApolloperceptionKeyValueArrayDouble>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayDouble &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayDouble & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayDouble & dt);
}
