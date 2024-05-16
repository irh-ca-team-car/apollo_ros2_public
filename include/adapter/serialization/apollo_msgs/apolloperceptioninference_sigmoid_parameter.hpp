#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_sigmoid_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSigmoidParameter &msg) ;
    ApolloperceptioninferenceSigmoidParameter from_json_ApolloperceptioninferenceSigmoidParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceSigmoidParameter from_json<ApolloperceptioninferenceSigmoidParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSigmoidParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSigmoidParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSigmoidParameter & dt);
}
