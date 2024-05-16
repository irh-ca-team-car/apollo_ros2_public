#pragma once
#include "apollo_msgs/msg/apolloperceptiononboard_radar_component_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardRadarComponentConfig &msg) ;
    ApolloperceptiononboardRadarComponentConfig from_json_ApolloperceptiononboardRadarComponentConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptiononboardRadarComponentConfig from_json<ApolloperceptiononboardRadarComponentConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardRadarComponentConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardRadarComponentConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardRadarComponentConfig & dt);
}
