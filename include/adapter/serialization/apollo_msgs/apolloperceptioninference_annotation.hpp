#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_annotation.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_normalized_b_box.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_b_box3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnnotation &msg) ;
    ApolloperceptioninferenceAnnotation from_json_ApolloperceptioninferenceAnnotation (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceAnnotation from_json<ApolloperceptioninferenceAnnotation>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnnotation &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnnotation & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnnotation & dt);
}
