#pragma once
#include "apollo_msgs/msg/apolloperception_v2_x_information.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionV2XInformation &msg) ;
    ApolloperceptionV2XInformation from_json_ApolloperceptionV2XInformation (nlohmann::json obj) ;
    template <>
    ApolloperceptionV2XInformation from_json<ApolloperceptionV2XInformation>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionV2XInformation &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionV2XInformation & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionV2XInformation & dt);
}
