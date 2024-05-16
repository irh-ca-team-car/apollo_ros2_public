#pragma once
#include "apollo_msgs/msg/apollorouting_curve_range.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_curve_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingCurveRange &msg) ;
    ApolloroutingCurveRange from_json_ApolloroutingCurveRange (nlohmann::json obj) ;
    template <>
    ApolloroutingCurveRange from_json<ApolloroutingCurveRange>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingCurveRange &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingCurveRange & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingCurveRange & dt);
}
