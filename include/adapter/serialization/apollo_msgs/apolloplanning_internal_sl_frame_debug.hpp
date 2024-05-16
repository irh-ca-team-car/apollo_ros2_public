#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_sl_frame_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_sl_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSLFrameDebug &msg) ;
    ApolloplanningInternalSLFrameDebug from_json_ApolloplanningInternalSLFrameDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalSLFrameDebug from_json<ApolloplanningInternalSLFrameDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSLFrameDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSLFrameDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSLFrameDebug & dt);
}
