#pragma once
#include "apollo_msgs/msg/apollohdmap_curve_segmentcurve_type.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_line_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapCurveSegmentcurveType &msg) ;
    ApollohdmapCurveSegmentcurveType from_json_ApollohdmapCurveSegmentcurveType (nlohmann::json obj) ;
    template <>
    ApollohdmapCurveSegmentcurveType from_json<ApollohdmapCurveSegmentcurveType>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapCurveSegmentcurveType &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapCurveSegmentcurveType & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapCurveSegmentcurveType & dt);
}
