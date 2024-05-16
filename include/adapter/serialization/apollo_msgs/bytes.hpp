#pragma once
#include "apollo_msgs/msg/bytes.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Bytes &msg) ;
    Bytes from_json_Bytes (nlohmann::json obj) ;
    template <>
    Bytes from_json<Bytes>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Bytes &dt);
    std::ostream & operator<<(std::ostream & os, const Bytes & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Bytes & dt);
}
