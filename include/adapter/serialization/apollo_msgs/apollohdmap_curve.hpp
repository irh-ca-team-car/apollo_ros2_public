#pragma once
#include "apollo_msgs/msg/apollohdmap_curve.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_curve_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapCurve &msg) ;
    ApollohdmapCurve from_json_ApollohdmapCurve (nlohmann::json obj) ;
    template <>
    ApollohdmapCurve from_json<ApollohdmapCurve>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapCurve &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapCurve & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapCurve & dt);
}
