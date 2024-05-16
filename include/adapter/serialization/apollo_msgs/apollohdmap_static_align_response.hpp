#pragma once
#include "apollo_msgs/msg/apollohdmap_static_align_response.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapStaticAlignResponse &msg) ;
    ApollohdmapStaticAlignResponse from_json_ApollohdmapStaticAlignResponse (nlohmann::json obj) ;
    template <>
    ApollohdmapStaticAlignResponse from_json<ApollohdmapStaticAlignResponse>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapStaticAlignResponse &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapStaticAlignResponse & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapStaticAlignResponse & dt);
}
