#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_region_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_anchor_box.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRegionParameter &msg) ;
    ApolloperceptioninferenceRegionParameter from_json_ApolloperceptioninferenceRegionParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceRegionParameter from_json<ApolloperceptioninferenceRegionParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRegionParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRegionParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRegionParameter & dt);
}
