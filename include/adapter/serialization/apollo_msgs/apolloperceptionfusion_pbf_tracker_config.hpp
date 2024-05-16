#pragma once
#include "apollo_msgs/msg/apolloperceptionfusion_pbf_tracker_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionPbfTrackerConfig &msg) ;
    ApolloperceptionfusionPbfTrackerConfig from_json_ApolloperceptionfusionPbfTrackerConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionfusionPbfTrackerConfig from_json<ApolloperceptionfusionPbfTrackerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionPbfTrackerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionPbfTrackerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionPbfTrackerConfig & dt);
}
