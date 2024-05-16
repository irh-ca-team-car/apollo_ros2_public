#pragma once
#include "apollo_msgs/msg/apollohdmap_header.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_projection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapHeader &msg) ;
    ApollohdmapHeader from_json_ApollohdmapHeader (nlohmann::json obj) ;
    template <>
    ApollohdmapHeader from_json<ApollohdmapHeader>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapHeader &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapHeader & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapHeader & dt);
}
