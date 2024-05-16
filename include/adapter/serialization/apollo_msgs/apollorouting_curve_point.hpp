#pragma once
#include "apollo_msgs/msg/apollorouting_curve_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingCurvePoint &msg) ;
    ApolloroutingCurvePoint from_json_ApolloroutingCurvePoint (nlohmann::json obj) ;
    template <>
    ApolloroutingCurvePoint from_json<ApolloroutingCurvePoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingCurvePoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingCurvePoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingCurvePoint & dt);
}
