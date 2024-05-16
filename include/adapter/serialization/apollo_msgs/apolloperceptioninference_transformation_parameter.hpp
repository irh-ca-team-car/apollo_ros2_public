#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_transformation_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_resize_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_noise_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_distortion_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_expansion_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_emit_constraint.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceTransformationParameter &msg) ;
    ApolloperceptioninferenceTransformationParameter from_json_ApolloperceptioninferenceTransformationParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceTransformationParameter from_json<ApolloperceptioninferenceTransformationParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceTransformationParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceTransformationParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceTransformationParameter & dt);
}
