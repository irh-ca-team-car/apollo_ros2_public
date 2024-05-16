#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_save_output_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_resize_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSaveOutputParameter &msg) ;
    ApolloperceptioninferenceSaveOutputParameter from_json_ApolloperceptioninferenceSaveOutputParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceSaveOutputParameter from_json<ApolloperceptioninferenceSaveOutputParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSaveOutputParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSaveOutputParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSaveOutputParameter & dt);
}
