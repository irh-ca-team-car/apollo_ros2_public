#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_dfmbpsroi_align_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDFMBPSROIAlignParameter &msg) ;
    ApolloperceptioninferenceDFMBPSROIAlignParameter from_json_ApolloperceptioninferenceDFMBPSROIAlignParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDFMBPSROIAlignParameter from_json<ApolloperceptioninferenceDFMBPSROIAlignParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDFMBPSROIAlignParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDFMBPSROIAlignParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDFMBPSROIAlignParameter & dt);
}
