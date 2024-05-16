#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_softmax_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSoftmaxParameter &msg) ;
    ApolloperceptioninferenceSoftmaxParameter from_json_ApolloperceptioninferenceSoftmaxParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceSoftmaxParameter from_json<ApolloperceptioninferenceSoftmaxParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSoftmaxParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSoftmaxParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSoftmaxParameter & dt);
}
