#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_sample_constraint.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSampleConstraint &msg) ;
    ApolloperceptioninferenceSampleConstraint from_json_ApolloperceptioninferenceSampleConstraint (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceSampleConstraint from_json<ApolloperceptioninferenceSampleConstraint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSampleConstraint &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSampleConstraint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSampleConstraint & dt);
}
