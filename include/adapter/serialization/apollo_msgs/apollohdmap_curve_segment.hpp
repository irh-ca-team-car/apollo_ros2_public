#pragma once
#include "apollo_msgs/msg/apollohdmap_curve_segment.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_curve_segmentcurve_type.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapCurveSegment &msg) ;
    ApollohdmapCurveSegment from_json_ApollohdmapCurveSegment (nlohmann::json obj) ;
    template <>
    ApollohdmapCurveSegment from_json<ApollohdmapCurveSegment>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapCurveSegment &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapCurveSegment & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapCurveSegment & dt);
}
