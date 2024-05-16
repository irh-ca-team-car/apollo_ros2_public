#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_salt_pepper_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSaltPepperParameter &msg) ;
    ApolloperceptioninferenceSaltPepperParameter from_json_ApolloperceptioninferenceSaltPepperParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceSaltPepperParameter from_json<ApolloperceptioninferenceSaltPepperParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSaltPepperParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSaltPepperParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSaltPepperParameter & dt);
}
