#pragma once
#include "apollo_msgs/msg/apollocommon_frenet_frame_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonFrenetFramePoint &msg) ;
    ApollocommonFrenetFramePoint from_json_ApollocommonFrenetFramePoint (nlohmann::json obj) ;
    template <>
    ApollocommonFrenetFramePoint from_json<ApollocommonFrenetFramePoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonFrenetFramePoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonFrenetFramePoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonFrenetFramePoint & dt);
}
