#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_input_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_shape.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceInputParameter &msg) ;
    ApolloperceptioninferenceInputParameter from_json_ApolloperceptioninferenceInputParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceInputParameter from_json<ApolloperceptioninferenceInputParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceInputParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceInputParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceInputParameter & dt);
}
