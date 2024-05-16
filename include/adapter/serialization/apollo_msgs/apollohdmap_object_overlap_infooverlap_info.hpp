#pragma once
#include "apollo_msgs/msg/apollohdmap_object_overlap_infooverlap_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_lane_overlap_info.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_crosswalk_overlap_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapObjectOverlapInfooverlapInfo &msg) ;
    ApollohdmapObjectOverlapInfooverlapInfo from_json_ApollohdmapObjectOverlapInfooverlapInfo (nlohmann::json obj) ;
    template <>
    ApollohdmapObjectOverlapInfooverlapInfo from_json<ApollohdmapObjectOverlapInfooverlapInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapObjectOverlapInfooverlapInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapObjectOverlapInfooverlapInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapObjectOverlapInfooverlapInfo & dt);
}
