#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_yolo_dump_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceYoloDumpParameter &msg) ;
    ApolloperceptioninferenceYoloDumpParameter from_json_ApolloperceptioninferenceYoloDumpParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceYoloDumpParameter from_json<ApolloperceptioninferenceYoloDumpParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceYoloDumpParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceYoloDumpParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceYoloDumpParameter & dt);
}
