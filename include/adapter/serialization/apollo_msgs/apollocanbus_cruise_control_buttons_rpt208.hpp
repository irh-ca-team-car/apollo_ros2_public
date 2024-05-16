#pragma once
#include "apollo_msgs/msg/apollocanbus_cruise_control_buttons_rpt208.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusCruiseControlButtonsRpt208 &msg) ;
    ApollocanbusCruiseControlButtonsRpt208 from_json_ApollocanbusCruiseControlButtonsRpt208 (nlohmann::json obj) ;
    template <>
    ApollocanbusCruiseControlButtonsRpt208 from_json<ApollocanbusCruiseControlButtonsRpt208>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusCruiseControlButtonsRpt208 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusCruiseControlButtonsRpt208 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusCruiseControlButtonsRpt208 & dt);
}
