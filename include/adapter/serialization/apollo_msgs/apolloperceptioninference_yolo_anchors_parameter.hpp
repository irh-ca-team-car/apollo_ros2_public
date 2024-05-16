#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_yolo_anchors_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceYoloAnchorsParameter &msg) ;
    ApolloperceptioninferenceYoloAnchorsParameter from_json_ApolloperceptioninferenceYoloAnchorsParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceYoloAnchorsParameter from_json<ApolloperceptioninferenceYoloAnchorsParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceYoloAnchorsParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceYoloAnchorsParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceYoloAnchorsParameter & dt);
}
