#pragma once
#include "apollo_msgs/msg/apolloperception_cipv_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionCIPVInfo &msg) ;
    ApolloperceptionCIPVInfo from_json_ApolloperceptionCIPVInfo (nlohmann::json obj) ;
    template <>
    ApolloperceptionCIPVInfo from_json<ApolloperceptionCIPVInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionCIPVInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionCIPVInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionCIPVInfo & dt);
}
