#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_image_data_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dataset_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceImageDataParameter &msg) ;
    ApolloperceptioninferenceImageDataParameter from_json_ApolloperceptioninferenceImageDataParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceImageDataParameter from_json<ApolloperceptioninferenceImageDataParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceImageDataParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceImageDataParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceImageDataParameter & dt);
}
