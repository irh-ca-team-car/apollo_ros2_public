#pragma once
#include "apollo_msgs/msg/apolloplanning_sl_boundary.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_sl_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSLBoundary &msg) ;
    ApolloplanningSLBoundary from_json_ApolloplanningSLBoundary (nlohmann::json obj) ;
    template <>
    ApolloplanningSLBoundary from_json<ApolloplanningSLBoundary>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSLBoundary &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSLBoundary & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSLBoundary & dt);
}
