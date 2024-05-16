#pragma once
#include "apollo_msgs/msg/vector3.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Vector3 &msg) ;
    Vector3 from_json_Vector3 (nlohmann::json obj) ;
    template <>
    Vector3 from_json<Vector3>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Vector3 &dt);
    std::ostream & operator<<(std::ostream & os, const Vector3 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Vector3 & dt);
}
