#pragma once
#include "apollo_msgs/msg/apollodata_software_infoconfigs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataSoftwareInfoconfigs &msg) ;
    ApollodataSoftwareInfoconfigs from_json_ApollodataSoftwareInfoconfigs (nlohmann::json obj) ;
    template <>
    ApollodataSoftwareInfoconfigs from_json<ApollodataSoftwareInfoconfigs>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataSoftwareInfoconfigs &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataSoftwareInfoconfigs & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataSoftwareInfoconfigs & dt);
}
