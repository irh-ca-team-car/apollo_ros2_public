#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_reshape_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_shape.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceReshapeParameter &msg) ;
    ApolloperceptioninferenceReshapeParameter from_json_ApolloperceptioninferenceReshapeParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceReshapeParameter from_json<ApolloperceptioninferenceReshapeParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceReshapeParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceReshapeParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceReshapeParameter & dt);
}
