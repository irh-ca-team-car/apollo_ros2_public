#pragma once
#include "apollo_msgs/msg/apollohdmap_pnc_junction.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_passage_group.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapPNCJunction &msg) ;
    ApollohdmapPNCJunction from_json_ApollohdmapPNCJunction (nlohmann::json obj) ;
    template <>
    ApollohdmapPNCJunction from_json<ApollohdmapPNCJunction>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapPNCJunction &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapPNCJunction & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapPNCJunction & dt);
}
