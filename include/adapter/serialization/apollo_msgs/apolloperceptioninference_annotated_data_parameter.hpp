#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_annotated_data_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_batch_sampler.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnnotatedDataParameter &msg) ;
    ApolloperceptioninferenceAnnotatedDataParameter from_json_ApolloperceptioninferenceAnnotatedDataParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceAnnotatedDataParameter from_json<ApolloperceptioninferenceAnnotatedDataParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnnotatedDataParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnnotatedDataParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnnotatedDataParameter & dt);
}
