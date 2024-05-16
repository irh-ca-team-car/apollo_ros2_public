#pragma once
#include "apollo_msgs/msg/apollohdmap_crosswalk_overlap_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapCrosswalkOverlapInfo &msg) ;
    ApollohdmapCrosswalkOverlapInfo from_json_ApollohdmapCrosswalkOverlapInfo (nlohmann::json obj) ;
    template <>
    ApollohdmapCrosswalkOverlapInfo from_json<ApollohdmapCrosswalkOverlapInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapCrosswalkOverlapInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapCrosswalkOverlapInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapCrosswalkOverlapInfo & dt);
}
