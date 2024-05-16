#pragma once
#include "apollo_msgs/msg/apolloperceptionfusion_probabilistic_fusion_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionProbabilisticFusionConfig &msg) ;
    ApolloperceptionfusionProbabilisticFusionConfig from_json_ApolloperceptionfusionProbabilisticFusionConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionfusionProbabilisticFusionConfig from_json<ApolloperceptionfusionProbabilisticFusionConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionProbabilisticFusionConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionProbabilisticFusionConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionProbabilisticFusionConfig & dt);
}
