#pragma once
#include "apollo_msgs/msg/regress_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/dense_parameter.hpp"
#include "adapter/serialization/apollo_msgs/activation_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const RegressParameter &msg) ;
    RegressParameter from_json_RegressParameter (nlohmann::json obj) ;
    template <>
    RegressParameter from_json<RegressParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, RegressParameter &dt);
    std::ostream & operator<<(std::ostream & os, const RegressParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const RegressParameter & dt);
}
