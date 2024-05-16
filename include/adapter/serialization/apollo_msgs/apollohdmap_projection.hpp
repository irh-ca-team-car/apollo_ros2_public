#pragma once
#include "apollo_msgs/msg/apollohdmap_projection.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapProjection &msg) ;
    ApollohdmapProjection from_json_ApollohdmapProjection (nlohmann::json obj) ;
    template <>
    ApollohdmapProjection from_json<ApollohdmapProjection>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapProjection &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapProjection & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapProjection & dt);
}
