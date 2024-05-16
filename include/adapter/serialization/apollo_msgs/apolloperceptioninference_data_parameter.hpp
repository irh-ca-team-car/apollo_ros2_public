#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_data_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDataParameter &msg) ;
    ApolloperceptioninferenceDataParameter from_json_ApolloperceptioninferenceDataParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDataParameter from_json<ApolloperceptioninferenceDataParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDataParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDataParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDataParameter & dt);
}
