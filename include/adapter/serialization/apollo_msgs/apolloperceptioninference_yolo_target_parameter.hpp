#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_yolo_target_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dimension_statistics.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceYoloTargetParameter &msg) ;
    ApolloperceptioninferenceYoloTargetParameter from_json_ApolloperceptioninferenceYoloTargetParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceYoloTargetParameter from_json<ApolloperceptioninferenceYoloTargetParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceYoloTargetParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceYoloTargetParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceYoloTargetParameter & dt);
}
