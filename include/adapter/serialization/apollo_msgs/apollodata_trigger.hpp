#pragma once
#include "apollo_msgs/msg/apollodata_trigger.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataTrigger &msg) ;
    ApollodataTrigger from_json_ApollodataTrigger (nlohmann::json obj) ;
    template <>
    ApollodataTrigger from_json<ApollodataTrigger>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataTrigger &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataTrigger & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataTrigger & dt);
}
