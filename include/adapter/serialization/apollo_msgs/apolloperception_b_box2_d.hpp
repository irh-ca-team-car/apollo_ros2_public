#pragma once
#include "apollo_msgs/msg/apolloperception_b_box2_d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionBBox2D &msg) ;
    ApolloperceptionBBox2D from_json_ApolloperceptionBBox2D (nlohmann::json obj) ;
    template <>
    ApolloperceptionBBox2D from_json<ApolloperceptionBBox2D>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionBBox2D &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionBBox2D & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionBBox2D & dt);
}
