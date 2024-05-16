#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_annotated_datum.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_datum.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotation_group.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnnotatedDatum &msg) ;
    ApolloperceptioninferenceAnnotatedDatum from_json_ApolloperceptioninferenceAnnotatedDatum (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceAnnotatedDatum from_json<ApolloperceptioninferenceAnnotatedDatum>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnnotatedDatum &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnnotatedDatum & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnnotatedDatum & dt);
}
