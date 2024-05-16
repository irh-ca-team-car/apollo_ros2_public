#pragma once
#include "apollo_msgs/msg/apollostorytelling_close_to_junction.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToJunction &msg) ;
    ApollostorytellingCloseToJunction from_json_ApollostorytellingCloseToJunction (nlohmann::json obj) ;
    template <>
    ApollostorytellingCloseToJunction from_json<ApollostorytellingCloseToJunction>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToJunction &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToJunction & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToJunction & dt);
}
