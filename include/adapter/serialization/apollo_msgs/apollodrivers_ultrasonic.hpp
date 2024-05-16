#pragma once
#include "apollo_msgs/msg/apollodrivers_ultrasonic.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversUltrasonic &msg) ;
    ApollodriversUltrasonic from_json_ApollodriversUltrasonic (nlohmann::json obj) ;
    template <>
    ApollodriversUltrasonic from_json<ApollodriversUltrasonic>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversUltrasonic &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversUltrasonic & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversUltrasonic & dt);
}
