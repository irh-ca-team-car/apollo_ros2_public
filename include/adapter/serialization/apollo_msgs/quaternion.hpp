#pragma once
#include "apollo_msgs/msg/quaternion.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Quaternion &msg) ;
    Quaternion from_json_Quaternion (nlohmann::json obj) ;
    template <>
    Quaternion from_json<Quaternion>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Quaternion &dt);
    std::ostream & operator<<(std::ostream & os, const Quaternion & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Quaternion & dt);
}
