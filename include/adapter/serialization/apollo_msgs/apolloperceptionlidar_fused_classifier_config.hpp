#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_fused_classifier_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarFusedClassifierConfig &msg) ;
    ApolloperceptionlidarFusedClassifierConfig from_json_ApolloperceptionlidarFusedClassifierConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarFusedClassifierConfig from_json<ApolloperceptionlidarFusedClassifierConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarFusedClassifierConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarFusedClassifierConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarFusedClassifierConfig & dt);
}
