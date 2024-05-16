#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_roi_pooling_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceROIPoolingParameter &msg) ;
    ApolloperceptioninferenceROIPoolingParameter from_json_ApolloperceptioninferenceROIPoolingParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceROIPoolingParameter from_json<ApolloperceptioninferenceROIPoolingParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceROIPoolingParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceROIPoolingParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceROIPoolingParameter & dt);
}
