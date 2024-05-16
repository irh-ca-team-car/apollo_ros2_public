#pragma once
#include "apollo_msgs/msg/apollohdmap_junction.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapJunction &msg) ;
    ApollohdmapJunction from_json_ApollohdmapJunction (nlohmann::json obj) ;
    template <>
    ApollohdmapJunction from_json<ApollohdmapJunction>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapJunction &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapJunction & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapJunction & dt);
}
