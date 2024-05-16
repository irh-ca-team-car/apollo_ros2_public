#pragma once
#include "apollo_msgs/msg/apollodata_environment_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataEnvironmentInfo &msg) ;
    ApollodataEnvironmentInfo from_json_ApollodataEnvironmentInfo (nlohmann::json obj) ;
    template <>
    ApollodataEnvironmentInfo from_json<ApollodataEnvironmentInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataEnvironmentInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataEnvironmentInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataEnvironmentInfo & dt);
}
