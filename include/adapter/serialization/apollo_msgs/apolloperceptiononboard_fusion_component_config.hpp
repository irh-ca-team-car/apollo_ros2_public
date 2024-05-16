#pragma once
#include "apollo_msgs/msg/apolloperceptiononboard_fusion_component_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardFusionComponentConfig &msg) ;
    ApolloperceptiononboardFusionComponentConfig from_json_ApolloperceptiononboardFusionComponentConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptiononboardFusionComponentConfig from_json<ApolloperceptiononboardFusionComponentConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardFusionComponentConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardFusionComponentConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardFusionComponentConfig & dt);
}
