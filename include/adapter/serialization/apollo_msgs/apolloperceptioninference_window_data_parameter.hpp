#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_window_data_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceWindowDataParameter &msg) ;
    ApolloperceptioninferenceWindowDataParameter from_json_ApolloperceptioninferenceWindowDataParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceWindowDataParameter from_json<ApolloperceptioninferenceWindowDataParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceWindowDataParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceWindowDataParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceWindowDataParameter & dt);
}
