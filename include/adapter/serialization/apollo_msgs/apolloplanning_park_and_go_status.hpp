#pragma once
#include "apollo_msgs/msg/apolloplanning_park_and_go_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningParkAndGoStatus &msg) ;
    ApolloplanningParkAndGoStatus from_json_ApolloplanningParkAndGoStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningParkAndGoStatus from_json<ApolloplanningParkAndGoStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningParkAndGoStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningParkAndGoStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningParkAndGoStatus & dt);
}
