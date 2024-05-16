#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_hybrid_model_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalHybridModelDebug &msg) ;
    ApolloplanningInternalHybridModelDebug from_json_ApolloplanningInternalHybridModelDebug (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalHybridModelDebug from_json<ApolloplanningInternalHybridModelDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalHybridModelDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalHybridModelDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalHybridModelDebug & dt);
}
