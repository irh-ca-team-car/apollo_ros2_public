#pragma once
#include "apollo_msgs/msg/apolloplanning_e_stop.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningEStop &msg) ;
    ApolloplanningEStop from_json_ApolloplanningEStop (nlohmann::json obj) ;
    template <>
    ApolloplanningEStop from_json<ApolloplanningEStop>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningEStop &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningEStop & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningEStop & dt);
}
