#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_net_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_shape.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_net_state.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_layer_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_v1_layer_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNetParameter &msg) ;
    ApolloperceptioninferenceNetParameter from_json_ApolloperceptioninferenceNetParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceNetParameter from_json<ApolloperceptioninferenceNetParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNetParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNetParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNetParameter & dt);
}
