#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_sample_layer_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_sl_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSampleLayerDebug &msg) ;
    ApolloplanningInternalSampleLayerDebug from_json_ApolloplanningInternalSampleLayerDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalSampleLayerDebug from_json<ApolloplanningInternalSampleLayerDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSampleLayerDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSampleLayerDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSampleLayerDebug & dt);
}
