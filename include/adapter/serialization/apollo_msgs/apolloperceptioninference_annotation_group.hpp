#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_annotation_group.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotation.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnnotationGroup &msg) ;
    ApolloperceptioninferenceAnnotationGroup from_json_ApolloperceptioninferenceAnnotationGroup (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceAnnotationGroup from_json<ApolloperceptioninferenceAnnotationGroup>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnnotationGroup &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnnotationGroup & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnnotationGroup & dt);
}
