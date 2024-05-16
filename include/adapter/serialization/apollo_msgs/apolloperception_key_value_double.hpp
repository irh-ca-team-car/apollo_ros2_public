#pragma once
#include "apollo_msgs/msg/apolloperception_key_value_double.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueDouble &msg) ;
    ApolloperceptionKeyValueDouble from_json_ApolloperceptionKeyValueDouble (nlohmann::json obj) ;
    template <>
    ApolloperceptionKeyValueDouble from_json<ApolloperceptionKeyValueDouble>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueDouble &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueDouble & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueDouble & dt);
}
