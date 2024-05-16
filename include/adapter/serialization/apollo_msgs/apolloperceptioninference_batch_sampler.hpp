#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_batch_sampler.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sampler.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sample_constraint.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBatchSampler &msg) ;
    ApolloperceptioninferenceBatchSampler from_json_ApolloperceptioninferenceBatchSampler (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceBatchSampler from_json<ApolloperceptioninferenceBatchSampler>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBatchSampler &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBatchSampler & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBatchSampler & dt);
}
