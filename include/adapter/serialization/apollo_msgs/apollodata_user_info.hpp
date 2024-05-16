#pragma once
#include "apollo_msgs/msg/apollodata_user_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataUserInfo &msg) ;
    ApollodataUserInfo from_json_ApollodataUserInfo (nlohmann::json obj) ;
    template <>
    ApollodataUserInfo from_json<ApollodataUserInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataUserInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataUserInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataUserInfo & dt);
}
