#pragma once
#include "apollo_msgs/msg/apollocommon_engage_advice.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonEngageAdvice &msg) ;
    ApollocommonEngageAdvice from_json_ApollocommonEngageAdvice (nlohmann::json obj) ;
    template <>
    ApollocommonEngageAdvice from_json<ApollocommonEngageAdvice>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonEngageAdvice &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonEngageAdvice & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonEngageAdvice & dt);
}
