#pragma once
#include "apollo_msgs/msg/records.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Records &msg) ;
    Records from_json_Records (nlohmann::json obj) ;
    template <>
    Records from_json<Records>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Records &dt);
    std::ostream & operator<<(std::ostream & os, const Records & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Records & dt);
}
