#pragma once
#include "apollo_msgs/msg/apollohdmap_crosswalk.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapCrosswalk &msg) ;
    ApollohdmapCrosswalk from_json_ApollohdmapCrosswalk (nlohmann::json obj) ;
    template <>
    ApollohdmapCrosswalk from_json<ApollohdmapCrosswalk>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapCrosswalk &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapCrosswalk & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapCrosswalk & dt);
}
