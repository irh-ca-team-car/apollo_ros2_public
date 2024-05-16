#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_sampler.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSampler &msg) ;
    ApolloperceptioninferenceSampler from_json_ApolloperceptioninferenceSampler (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceSampler from_json<ApolloperceptioninferenceSampler>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSampler &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSampler & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSampler & dt);
}
