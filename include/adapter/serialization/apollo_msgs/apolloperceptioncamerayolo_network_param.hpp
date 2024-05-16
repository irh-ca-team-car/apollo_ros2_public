#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerayolo_network_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerayoloNetworkParam &msg) ;
    ApolloperceptioncamerayoloNetworkParam from_json_ApolloperceptioncamerayoloNetworkParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerayoloNetworkParam from_json<ApolloperceptioncamerayoloNetworkParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerayoloNetworkParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerayoloNetworkParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerayoloNetworkParam & dt);
}
