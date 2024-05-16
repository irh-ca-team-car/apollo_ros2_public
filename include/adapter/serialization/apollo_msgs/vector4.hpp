#pragma once
#include "apollo_msgs/msg/vector4.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Vector4 &msg) ;
    Vector4 from_json_Vector4 (nlohmann::json obj) ;
    template <>
    Vector4 from_json<Vector4>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Vector4 &dt);
    std::ostream & operator<<(std::ostream & os, const Vector4 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Vector4 & dt);
}
