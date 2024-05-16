#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_parameter_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_shape.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceParameterParameter &msg) ;
    ApolloperceptioninferenceParameterParameter from_json_ApolloperceptioninferenceParameterParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceParameterParameter from_json<ApolloperceptioninferenceParameterParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceParameterParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceParameterParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceParameterParameter & dt);
}
