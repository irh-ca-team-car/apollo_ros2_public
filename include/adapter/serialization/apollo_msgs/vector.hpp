#pragma once
#include "apollo_msgs/msg/vector.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Vector &msg) ;
    Vector from_json_Vector (nlohmann::json obj) ;
    template <>
    Vector from_json<Vector>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Vector &dt);
    std::ostream & operator<<(std::ostream & os, const Vector & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Vector & dt);
}
