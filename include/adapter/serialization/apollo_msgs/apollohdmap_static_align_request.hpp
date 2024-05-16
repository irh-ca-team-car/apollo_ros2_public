#pragma once
#include "apollo_msgs/msg/apollohdmap_static_align_request.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapStaticAlignRequest &msg) ;
    ApollohdmapStaticAlignRequest from_json_ApollohdmapStaticAlignRequest (nlohmann::json obj) ;
    template <>
    ApollohdmapStaticAlignRequest from_json<ApollohdmapStaticAlignRequest>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapStaticAlignRequest &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapStaticAlignRequest & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapStaticAlignRequest & dt);
}
