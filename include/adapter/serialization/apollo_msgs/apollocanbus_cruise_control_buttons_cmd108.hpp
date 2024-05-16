#pragma once
#include "apollo_msgs/msg/apollocanbus_cruise_control_buttons_cmd108.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusCruiseControlButtonsCmd108 &msg) ;
    ApollocanbusCruiseControlButtonsCmd108 from_json_ApollocanbusCruiseControlButtonsCmd108 (nlohmann::json obj) ;
    template <>
    ApollocanbusCruiseControlButtonsCmd108 from_json<ApollocanbusCruiseControlButtonsCmd108>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusCruiseControlButtonsCmd108 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusCruiseControlButtonsCmd108 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusCruiseControlButtonsCmd108 & dt);
}
