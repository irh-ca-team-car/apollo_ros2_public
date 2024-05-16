#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_region_output_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_non_maximum_suppression_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_anchor_box.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRegionOutputParameter &msg) ;
    ApolloperceptioninferenceRegionOutputParameter from_json_ApolloperceptioninferenceRegionOutputParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceRegionOutputParameter from_json<ApolloperceptioninferenceRegionOutputParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRegionOutputParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRegionOutputParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRegionOutputParameter & dt);
}
