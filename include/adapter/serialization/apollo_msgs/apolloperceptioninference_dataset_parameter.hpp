#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_dataset_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_repeated_list.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDatasetParameter &msg) ;
    ApolloperceptioninferenceDatasetParameter from_json_ApolloperceptioninferenceDatasetParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDatasetParameter from_json<ApolloperceptioninferenceDatasetParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDatasetParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDatasetParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDatasetParameter & dt);
}
