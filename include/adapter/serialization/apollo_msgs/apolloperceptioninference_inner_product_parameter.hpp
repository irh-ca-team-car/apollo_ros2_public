#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_inner_product_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceInnerProductParameter &msg) ;
    ApolloperceptioninferenceInnerProductParameter from_json_ApolloperceptioninferenceInnerProductParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceInnerProductParameter from_json<ApolloperceptioninferenceInnerProductParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceInnerProductParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceInnerProductParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceInnerProductParameter & dt);
}
