#pragma once
#include "apollo_msgs/msg/apollostorytelling_close_to_yield_sign.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToYieldSign &msg) ;
    ApollostorytellingCloseToYieldSign from_json_ApollostorytellingCloseToYieldSign (nlohmann::json obj) ;
    template <>
    ApollostorytellingCloseToYieldSign from_json<ApollostorytellingCloseToYieldSign>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToYieldSign &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToYieldSign & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToYieldSign & dt);
}
