#pragma once
#include "apollo_msgs/msg/apollohdmap_dynamic_align_request.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapDynamicAlignRequest &msg) ;
    ApollohdmapDynamicAlignRequest from_json_ApollohdmapDynamicAlignRequest (nlohmann::json obj) ;
    template <>
    ApollohdmapDynamicAlignRequest from_json<ApollohdmapDynamicAlignRequest>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapDynamicAlignRequest &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapDynamicAlignRequest & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapDynamicAlignRequest & dt);
}
