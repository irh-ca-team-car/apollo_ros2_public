#pragma once
#include "apollo_msgs/msg/apollohdmap_object_overlap_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_object_overlap_infooverlap_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapObjectOverlapInfo &msg) ;
    ApollohdmapObjectOverlapInfo from_json_ApollohdmapObjectOverlapInfo (nlohmann::json obj) ;
    template <>
    ApollohdmapObjectOverlapInfo from_json<ApollohdmapObjectOverlapInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapObjectOverlapInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapObjectOverlapInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapObjectOverlapInfo & dt);
}
