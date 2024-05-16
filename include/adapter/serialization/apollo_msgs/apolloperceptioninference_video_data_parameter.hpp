#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_video_data_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceVideoDataParameter &msg) ;
    ApolloperceptioninferenceVideoDataParameter from_json_ApolloperceptioninferenceVideoDataParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceVideoDataParameter from_json<ApolloperceptioninferenceVideoDataParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceVideoDataParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceVideoDataParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceVideoDataParameter & dt);
}
