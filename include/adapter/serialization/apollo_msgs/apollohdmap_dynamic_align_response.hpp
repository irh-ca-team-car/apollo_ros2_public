#pragma once
#include "apollo_msgs/msg/apollohdmap_dynamic_align_response.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapDynamicAlignResponse &msg) ;
    ApollohdmapDynamicAlignResponse from_json_ApollohdmapDynamicAlignResponse (nlohmann::json obj) ;
    template <>
    ApollohdmapDynamicAlignResponse from_json<ApollohdmapDynamicAlignResponse>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapDynamicAlignResponse &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapDynamicAlignResponse & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapDynamicAlignResponse & dt);
}
