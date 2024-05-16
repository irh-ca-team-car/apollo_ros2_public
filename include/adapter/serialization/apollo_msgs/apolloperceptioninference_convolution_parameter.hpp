#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_convolution_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceConvolutionParameter &msg) ;
    ApolloperceptioninferenceConvolutionParameter from_json_ApolloperceptioninferenceConvolutionParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceConvolutionParameter from_json<ApolloperceptioninferenceConvolutionParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceConvolutionParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceConvolutionParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceConvolutionParameter & dt);
}
