#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_emit_constraint.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceEmitConstraint &msg) ;
    ApolloperceptioninferenceEmitConstraint from_json_ApolloperceptioninferenceEmitConstraint (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceEmitConstraint from_json<ApolloperceptioninferenceEmitConstraint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceEmitConstraint &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceEmitConstraint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceEmitConstraint & dt);
}
