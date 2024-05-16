#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_batch_norm_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBatchNormParameter &msg) ;
    ApolloperceptioninferenceBatchNormParameter from_json_ApolloperceptioninferenceBatchNormParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceBatchNormParameter from_json<ApolloperceptioninferenceBatchNormParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBatchNormParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBatchNormParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBatchNormParameter & dt);
}
