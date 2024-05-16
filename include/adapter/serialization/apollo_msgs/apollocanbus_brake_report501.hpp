#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_report501.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeReport501 &msg) ;
    ApollocanbusBrakeReport501 from_json_ApollocanbusBrakeReport501 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeReport501 from_json<ApollocanbusBrakeReport501>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeReport501 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeReport501 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeReport501 & dt);
}
