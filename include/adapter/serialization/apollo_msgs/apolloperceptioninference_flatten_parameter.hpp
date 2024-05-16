#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_flatten_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceFlattenParameter &msg) ;
    ApolloperceptioninferenceFlattenParameter from_json_ApolloperceptioninferenceFlattenParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceFlattenParameter from_json<ApolloperceptioninferenceFlattenParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceFlattenParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceFlattenParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceFlattenParameter & dt);
}
